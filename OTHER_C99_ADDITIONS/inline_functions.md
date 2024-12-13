- _inline_ anahtar sözcüğü C diline _C99_ Standardı ile eklendi. _C99_ ile eklenen diğer anahtar sözcüklerden farklı olarak __Inline_ yerine doğrudan _inline_ anahtar sözcüğü seçildi. (C99 standardı ile eklenen diğer anahtar sözcükler _ karakteri ve ondan sonra gelen büyük harf ile başlıyor: \_Alignof, \_Alignas_ gibi). inline anahtar sözcüğü standarda göre bir _function specifier_.
- Daha önce _inline_ fonksiyonlar için derleyici eklentileri kullanılıyordu.
- Bir fonksiyonun _inline_ anahtar sözcüğü ile tanımlanması derleyiciye bu fonksiyona yapılan çağrı için _"inline expansion"_ optimizasyonu ricası anlamında.

C++ dilinde de _inline_ fonksiyonlar var. Ancak C ve C++ dilleri arasında _inline_ anahtar sözcüğünün kullanılmasında bazı farklılıklar var.

C dilinde _inline_ fonksiyonlar, fonksiyonel makrolara (daha güvenli) bir seçenek oluşturabilir.
_inline_ fonksiyonlar diğer normal fonksiyonlar  gibi tanımlanırlar. 
Derleyici _inline_ fonksiyonların tanımı ve çağrıları üstünde tüm kontrolleri yapar. 
Ancak bir _inline_ fonksiyon çağrıldığında derleyici onu bir fonksiyon gibi çağırmak yerine bizzat onun iç kodunu çağırma yerine enjekte edebilir. 
Böylece _C99_ ve sonrasında artık fonksiyon çağırma işlemini elimine etmek için küçük fonksiyonların makro yerine _inline_ fonksiyon biçiminde yazılması tavsiye edilmektedir. 
Zaten _inline_ fonksiyonlar fonksiyonel makroların daha önce ele aldığımız dezavantajlarından kaçınmak amacıyla dile sokulmuştur. 

- _inline_ olmayan fonksiyonlar ile aynı semantik yapıya sahipler.
- Makroların adresi alınamaz ancak _inline_ fonksiyonlar, fonksiyon olduklarından adresleri alınabilir.

_necati.h_ bir başlık dosyası olsun:

```C
//necati.h

inline int foo(int x, int y)
{
  return x * x + y;
} 
```

Bir başka modülden bu başlık dosyası _include_ edildiğinde derleyici bu fonksiyonun tanımını görecek ve _inline expansion_ optimizasyonu yapabilecek.
Ancak derleyici sadece bunu gördüğünde object modüle bir _weak_ ya da _strong_ referans yazmayacak. 
Derleyici bu fonksiyonun _external_ olduğunu varsayacak ve fonksiyon çağrısını buna göre oluşturacak. 
Yani bu fonksiyonun tanımı bir başka dosyada yok ise _link_ zamanında çağrılan fonksiyon referansı linker tarafından bulunamadığı için hata oluşacak.
Bu durumda bu fonksiyonun bir modülde tanımlanması gerekiyor.

eğer _non-inline copy_ oluşturulması için bir neden yoksa bir sorun oluşmaz
- Derleyici _inline_ anahtar sözcüğü ile yapılan tanımdan _inline expansion_ optimizasyonu yapabilir.
- Ancak fonksiyonun fonksiyonun adresi alındığında derleyici fonksiyonun _non-inline_ bir kopyasını oluşturmak zorunda.
- _non-inline_ kopya dış bağlantıdır.

Bunun için kod dosyalarından birinde şunu yapmamız gerekiyor:

```C
//necati.c
#include "necati.h"
int foo(int x, int y);
```
ya da

```C
//necati.c
#include "necati.h"
extern int foo(int x, int y);
```
ya da  

```C
//necati.c
#include "necati.h"
extern inline int foo(int x, int y);
```

Ancak kesinlikle aşağıdaki gibi yazılmamalı:

```C
//necati.c
#include "necati.h"
inline int foo(int x, int y);
```

Bunun anlamı şu: <br>
Bu fonksiyon için _non-inline copy_ oluşturulması gerektiğinde burada oluşturulmalı. 
Burada ilginç bir şekilde, normal fonksiyonların tersine, _inline_ fonksiyonların tanımını başlık dosyasında yapıp bildirimini kod dosyasında yapıyoruz.

GNU derleyicisi C yerine C++'taki semantiği uyguluyor. (C++ açıklaması)

Bir başka seçenek başlık dosyasında _static_ anahtar sözcüğü ile tanımlamak.
Bu durumda _inline expansion_ olmaz ise her kod dosyası derlendiğinde iç bağlantıda ayrı bir kopya oluşur<br>

_inline_ fonksiyonlar üç ayrı şekilde tanımlanabilirler. 
Bu tanımlanma biçimleri inline fonksiyonların ele alınma biçimleri üzerinde farklılık oluşturur:

**- inline<br>**
Derleyici _inline_ yerleştirme _(inline expansion)_ yaparsa bir sorun olmaz. Ancak yapamaz ise derleyici _CALL_ makine komutunu yerleştirir. 
Başka modülde bu fonksiyon yoksa bağlama _(link)_ aşamasında hata oluşur.
**- static inline**<br>
 Derleyici _inline_ yerleştirme yapsa da yapmasa da bir sorun oluşmaz. 
Ancak fonksiyonu inline yerleştiremez ise iç bağlantıya _(internal linkage)_ sahip biçimde amaç dosyaya yazar ve fonksiyonu _CALL_ makine komutuyla çağırır.
**- extern inline<br>**
Derleyici _inline_ yerleştirme yaparsa sorun olmaz. Yapamaz ise _CALL_ makine komutunu kullanır. 
Ancak her zaman derleyici fonksiyonu amaç dosyaya _extern linkage_'a sahip olacak biçimde yazar. 
Dolayısıyla birden fazla modülde bu fonksiyonun tanımı olduğunda bağlantı aşamasında hata oluşur. 

Eğer _inline fonksiyon_ derleyici tarafından inline yerleştirme yapamıyor ise bir sorun oluşmasın istiyorsak _static inline_ tanımlamasını tercih edebiliriz.
Ya da _inline_ tanımlamasını tercih edip ayrıca fonksiyonun _static_ olmayan bir tanımlamasını başka bir modülde bulundurmalıyız. 
Programcılar tarafından en çok tercih edilen biçim _"static inline"_ biçimidir. 
_inline_ fonksiyonlar her derleme işleminde derleyici tarafından görülmek zorundadır. 
Dolayısıyla bu fonksiyonlar başlık dosyalarında bulunurlar. Birden fazla modülle çalıştığımızda _inline_ fonksiyonları ortak bir başlık dosyasına yerleştirebiliriz. 

<!---
Örneğin:

```C
/* project.h */

#ifndef PROJECT_H_
#define PROJECT_H_

static inline foo()
{
...
}

#endif

/* sample.c */

#include <stdio.h>
#include "project.h"
...

/* mample.c */

#include <stdio.h>
#include "project.h"
```
--->




<!---
<br>The idea is that "inline" can be used in a header file, and then "extern inline" in a .c file. "extern inline" is just how you instruct the compiler which object file should contain the (externally visible) generated code.<br>
inline: like GNU89 "extern inline"; no externally visible function is emitted, but one might be called and so must exist
extern inline: like GNU89 "inline": externally visible code is emitted, so at most one translation unit can use this.
static inline: like GNU89 "static inline". This is the only portable one between gnu89 and c99
kaan notlar
===========
Daha önce küçük kod parçalarının "fonksion çağrılarını elimine etmek" için makro biçiminde yazılabileceğini söylemiştik. 
Örneğin bir tam sayının karesini hesaplayan bir fonksiyon söz konusu olsun:
```C
int square(int a)
{
	return a * a;
}
```
Biz de bu fonksiyonu şöyle çağırmış olalım:

```C
	result = square(++x);
```

Burada bir sorun yok. 
Çünkü önce argümanın değeri hesaplanmakta daha sonra parametre değişkenine kopyalama yapılmaktadır. 
Şimdi de bu fonksiyonu makro biçiminde yazalım:

```C
#define square(a)		((a) * (a))
```
Artık makronun aşağıdaki gibi kullanımı "tanımsız davranış (undefined behavior)" oluşturacaktır:

```C
result = square(++x);
```

İşte fonksiyonları fonksiyon çağrılarını elimine etmek için makro biçiminde yazmak şu nedenlerden dolayı sorunlu bir konudur. 
- Makro yazımı zordur. Makro parametrelerinin parantez içerisine alınması, makronun en dıştan paranteze alınması aokunabilirliği zorlaştırmaktadır.
- Makro yazımının birden fazla satıra yaydırılması zordur.
- Makro açımı önişlemci tarafından yapıldığı için çeşitli kontroller makrolar üzerinde sağlanamamaktadır.
- Makroların çağrılması sırasında tanımsız davranışların oluşmaması için dikkat edilmesi gerekmektedir.
- Makrolar içerisinde bloklu işlemleri oluşturmak zordur. 

İşte fonksiyon çağrılarını elimine etmek makrolara daha iyi bir alternatif oluşturan ""inline fonksiyonlar" denilen bir fonksiyon çeşidi düşünülmüştür. 
inline fonksiyonlar C'ye resmi olarak C99 ile birlikte sokulmuştur. 
Ancak C++'ta ilk standartlardan beri (C++98) inline fonksiyon bulunmaktadır.
Her ne kadar inline fonksiyonlar C'ye C99 ile resmi olarak sokulmuşsa da aslında derleyicilerin önemli bir bölümü bir "eklenti (extension)" biçiminde 	inline fonksiyonları destekliyordu. 
Ancak standart öncesinde derleyicilerin inline fonksiyon semantikleri arasında küçük farklılıklar bulunabiliyordu. 
Her ne kadar C++ Programlama Dili C programlama Dilini kapsıyorsa da C++'ın inline fonksiyon semantiği ile C99'un inline fonksiyon semantiği arasında farklılıklar bulunmaktadır. Biz burada C99 ile C'ye eklenmiş olan inline fonksiyon semantiği üzerinde duracağız.  <br>

Bir fonksiyonu inline yapmak için tek yapılacak şey fonksiyonun başına aşağıdaki belirleyicileri getirmektir:

```
inline
static inline (ya da inline static)
extern inline (ya da inline extern)
```
inline anahtar sözcüğü C99'da "fonksiyon belirleyicisi (function specifier)" denilen bir gruba dahil edilmiştir. <br>
inline fonksiyon çağrıldığında derleyici koda fonksiyon çağırma kodu (CALL komutu) eklemek yerine doğrudan kodun iç kısmını tıpkı bir makroymuş gibi çağrılma yerine enjekte edebilmektedir. Örneğin:

```
inline int square(int a)
{
	return a * a;
}
```C

Burada biz fonksiyonu şöyle çağırmış olalım:

```C
result = square(1 + 2);
```
Derleyici square fonksiyonunu çağırmak yerine fonksiyonun içkodunu çağırma yerine enjekte edebilmektedir:

```C
	result = 3 * 3;
```

Böylece daha önce görmüş olduğumuz makrolara benzer bir etki yaratılmış olur. Ancak bu etki önişlemci tarafından değil bizzat derleme modülü tarafından sağlanmaktadır. <br>

inline fonksiyonlar normal bir fonksiyon gibi yazılmaktadır. derleyici inline fonksiyonlar üzerinde normal fonksiyonlarda yaptığı bütün kontrolleri yapmaktadır. Ancak bir inline fonksiyon çağrıldığında derleyici onu bir fonksiyon gibi çağırmak yerine bizzat onun iç kodunu çağırma yerine enjekte edebilmektedir. Böylece C99 ve sonrasında artık fonksiyon çağırma işlemini elimine etmek için küçük fonksiyonların makro yerine inline fonksiyon biçiminde yazılması tavsiye edilmektedir. Zaten inline fonksiyonlar makroların yukarıda sıraladığımız olumsuzluklarını gidermek amacıyla dile sokulmuştur. <br>

Ancak C'de inline fonksiyonların bazı ayrıntıları vardır. 
Öncelikle "inline" belirleyicisi "bir emir değil rica" niteliğindedir. 
Yani biz bir fonksiyonu inline yaptığımız zaman derleyici o fonksiyonu inline olarak açmayabilir. 
inline fonksiyonların derleyiciler tarafından inline olarak açılmaları zorunlu değildir. 
Pek çok derleyicide "inline açım (inline expansion)" derleyicinin optimizasyon seçenekleriyle ilişkilendirilmiştir. 
Yani derleyicilerin optimizasyon seçenekleri açılmazsa genellikle derleyiciler inline açım yapmamaktadır. 
Microsoft derleyicilerinin inline açım yapması için en azından /O2 optimizasyon seçeneğinin kullanılması gcc ve clang derleyicilerinde de en azından -O2 seçeneğinin kullanılması gerekmektedir. Örneğin:
```C	
cl /O2 sample.c					(Microsoft)
gcc -O2 -o sample sample.c		(gcc)
```
Tabii programcı bu derleyicilerde optimizasyon seçeneklerini açmış olsa bile derleyici yine de inline açımı yapmayabilir. Derleyiciler genellikle inline 
açım yapmaması durumunda herhangi bir uyarı vermezler. Programcı inline açımın yapılıp yapılmadığını ancak derleyicinin ürettiği kodu inceleyerek anlayabilmektedir. 
Pekiyi derleyici neden fonksiyonu inline açmak istemeyebilmektedir? Bunun çeşitli nedenleri olabilir. Örneğin:

- Özyinelemeli fonksiyonların inline açımları mümkün olmayabilir. 
- İçlerinde karmaşık deyimler olan fonksiyonalar (örneğin iç içe if deyimleri gibi) inline açılamayabilir. 
- Çalışması uzun zaman alan kodların inline olarak açılması uygun değldir. Örneğin bir fonksiyonun içerisinde 1000000 kere dönen büyük 
bir döngü olsun. Böyle bir fonksiyonun inline açılmasının bir faydası olmayacağı gibi kodu büyütebilmesi gibi zararları söz konusu olabilmektedir. 
- Fonksiyonun adresi alınıp kod içerisinde kullanılıyorsa derleyici fonksiyonu inline olarak açmak istemeyebilir. 
- Fonksiyon çok fazla satırdan oluşuyorsa inline açım kodu ciddi biçimde büyütebilecektir. 
Derleyiciler bu durumda inline açım yapmak istemeyebilirler.

Tersten gidersek "basit, birkaç satırlık, uzun döngüler ve karmaşık if deyimleri gibi deyimleri içermeyen" fonksiyonlar inline olarak açılmaya aday fonksiyonlardır. 

Pekiyi derleyici inline fonksiyonu inline olarak açmazsa ne yapacaktır? İşte bu durumda C99 ve sonrasında fonksiyonun nasıl inline tanımlandığna göre 
derleyicinin davranışı farklılaşmaktadır. Yukarıda da belirttiğimiz gibi C'de inline fonksiyonlar üç biçimde olabilmektedir:

inline
static inline
extern inline

C++'ta böyle bir ayrım yoktur. Ancak C'de yukarıdaki üç inline tanımlama farklı anlamlara gelmektedir. 

Eğer C'de _inline_ fonksiyon _static_ ya da _extern_ anahtar sözcüğü olmadan yalnızca _inline_ anahtar sözcüğü ile tanımlanmışsa bu durumda derleyici fonksiyonu
_inline_ olarak açarsa bir sorun oluşmaz. Ancak derleyici fonksiyonu inline olarak açamaz ise fonksiyonun tanımlamasını amaç kod içerisine yerleştirmez. 
Yani sanki fonksiyon 
hiç tanımlanmamış gibi işlem yapar. Fakat fonksiyonu CALL makine komutuyla çağırır. İşte bu durumda eğer _inline_ açım yapılamadıysa ve başka bir modülde de 
aynı isimli bir fonksiyon yoksa muhtemelen link aşamasında çağrılan fonksiyonu linker'ın bulamaması biçiminde hata  ile sonuçlanacaktır. Örneğin:

```C
/* sample.c  */

#include <stdio.h>

inline int square(int a)
{
	return a * a;
}

int main(void)
{
	int result;
	result = square(3);
	printf("%d\n", result);
}
```

Burada _square_ fonksiyonu _static_ ya da _extern_ belirleyicisi olmadan yalnızca _inline_ belirleyicisi ile tanımlanmıştır. Eğer fonksiyon _inline_ açılamazsa
link aşamasında eror olulacaktır. Örneğin biz gcc derleyicisinde fonksiyonu optimizasyon seçeneklerini açmadan aşağıdaki gibi derlemek isteyelim:

```
gcc -o sample sample.c
```

Bu durumda link aşamasında şöyle bir hata alırız:

```
/usr/bin/ld: /tmp/ccWaZ5zm.o: in function `main':
sample.c:(.text+0x1d): undefined reference to `square'
collect2: error: ld returned 1 exit status
```

Ancak biz programo -O2 seçeneği ile derlersek derleyici inline açım yapacağı için her ne kadar square fonksiyonunu amaç koda yerleştirmeyecekse de programın derlenip çalışmasında muhtemelen bir hata oluşmayacaktır:

```
gcc -O2 -o sample sample.c
```

Yalnızca _inline_ belirleyicisi ile fonksiyonu tanımladığımızda derleyici _inline_ açımı yapsın ya da yapmasın fonksiyon kodunu amaç koda yazmamaktadır.<br>
 _static inline_ fonksiyonlar eğer derleyici tarafından _inline_ olarak açılmazlarsa _static_ biçimde amaç dosyaya yerleştirilmektedir. 
 Böylece derleyici _CALL_ makine komutu ile bu _static_ fonksiyonu çağırmış olmaktadır. 
Yani bu durumda derleyici _inline_ fonksiyonu açsa da açmasa da programın derlenip çalışmasında bir sorun oluşmayacaktır. Örneğin:

```C
static inline int square(int a)
{
	return a * a;
}
```
Tabii static inline fonksiyonlarda derleyici inline açımı yaparsa aslında fonksiyonu hiç amaç dosyaya yazmayabilir. 
Ancak inline açımı yapamazsa _static_ düzeyde fonksiyonu amaç dosyaya yazacaktır. 
Tabii fonksiyon _static_ olduğu için fonksiyonun başka bir modülden çağrılması mümkün olmayacaktır. 
_static inline_ fonksiyonlar C'de en çok kullanılan _inline_ fonksiyonlardır. 
Ancak bunların da en önemli dezavantajı birden fazla modülde aynı _static inline_ fonksiyonun kullanılması durumunda eğer inline açım yapılamazsa bu fonksiyonların kodlarının ayrı ayrı bu modüllerde bulunması zorunluluğudur. 

Normal bir fonksiyon zaten extern biçimdedir. 
Yani onun tanımlamasının önüne extern getirilip getirilmemesinin bir farkı yoktur. Örneğin:
```C
extern void foo(void)
{
	//...
}
```

Burada extern belirleyicisi gereksiz kullanılmıştır. Fonksiyonlar zaten default external linkage'a sahiptir. Ancak _extern_ anahtar sözcüğü ile 
_inline_ anahtar sözcüğü bir arada kullanılırsa bu başka bir anlam ifade etmektedir. _extern inline_ fonksiyonlar derleyici tarafından inline açılsalar da açılmasalar da 
her zaman object dosyaya _extern linkage_ biçiminde yazılırlar. Örneğin:

```C
extern inline int square(int a)
{
	return a * a;
}
```

Burada fonksiyon _extern inline_ olarak tanımlanmıştır. 
Derleyici çağrı sırasında bu fonksiyonu _inline_ olarak açsa da açmasa da kod yine bu fonksiyonu normal external linkage'a sahip bir fonksiyon olarak yazmaktadır. 
Bu durumun dezavatajı şudur: Biz extern inline fonksiyonu birden fazla modülde kullanırsak ve bu fonksiyon inline açılmazsa fonksiyonun birden fazla extern tanımalaması modüllerde bulunur. Bu da link aşamasında soruna yol açar. <br>

