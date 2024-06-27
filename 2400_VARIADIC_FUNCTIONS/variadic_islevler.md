Bir işlevin istenilen sayıda değerle çağrılması programlamada genel bir ihtiyaç ve programlama dillerinin çoğunda bu ihtiyacı karşılamaya yönelik araç ya da araçlar vardır. Özellikle giriş çıkış işlemlerine _(input - output operations)_ yönelik hizmet veren kütüphanelerde böyle işlevler tercih edilir. Böyle işlevlere İngilizcede popüler olarak _"variadic function"_ denmektedir. Bu terim yerine Türkçede _"istenilen sayıda argüman ile çağrılabilen işlev"_ terimini önerebilirim. Çağrıyı yapan kod böyle işlevlere, ne yaptırmak istediğine bağlı olarak, farklı sayıda veri gönderebilir.

Örnekler verelim:
_print_ isimli bir işlev kendisine gönderilen her bir ifadenin değerini ekrana yazdırıyor olabilir. <br>
_get_mean_ isimli bir işlev kendisine gönderilen tam sayıların aritmetik ortalamasını hesaplıyor olabilir. <br>
_concat_ isimli bir işlev kendisine gönderilen yazıları birleştirip tek bir yazı oluşturuyor olabilir. <br>
 _push_back_vals_ isimli işlev kendisine gönderilen değerleri bir dinamik diziye ekliyor olabilir.

Farklı programlama dillerinin böyle bir işlevin oluşturulmasını sağlayan farklı araçları vardır. Örneğin C++ dilinde bu yapı için ağırlıklı olarak türden bağımsız programlama _(generic programming)_ paradigmasına destek veren araçlardan faydalanılır. Bu yazıda C dilinde değişken sayıda argümanla çağrılabilen işlevleri ayrıntılı olarak inceleyeceğiz.

C dilinde bir işlevin _"variadic"_ olduğunu gösteren ... atomudur. Yan yana yazılmış üç nokta karakterinin oluşturduğu atoma _(token)_ İngilizcede _ellipsis_ denir. Bir işlevin _"variadic"_ olması için son parametre değişkeni olarak ... atomunun yazılması gerekir. Üç nokta atomu atomu ile gösterilen parametreye bundan sonra _"variadic parametre"_ diyeceğiz

```C
void print(int n, ...);
int sum(int n, ...);
double ave(int, int, ...)
```

_variadic_ fonksiyon bildiriminin ya da tanımının geçerli olabilmesi için şu koşulların da sağlanması gerekir:
- fonksiyonun birden fazla _variadic_ parametresi olamaz.
- _variadic_ parametre son parametre olmalıdır.
- _variadic_ parametreden önce en az bir parametre değişkeni daha olmalıdır.

Bu işlevlerin çağrılmasına ilişkin genel kural şudur : Çağrıyı yapan kod _"variadic"_ parametreden önce yer alan türleri belirtilmiş tüm parametre değişkenlerine argüman göndermek zorundadır. _variadic_ parametre için kendi seçimine bağlı olarak _(opsiyonel olarak)_ dilediği sayıda argüman olarak gönderilebilir. Aşağıdaki kodu inceleyelim:

```C
void func(int, int, ...);
int main(void)
{
    func(10, 20, 30, 40);
    func(1, 3, 5);
    func(2, 4);
    func(2); //geçersiz
    func(0); //geçersiz
}
```

#### tür kontrolü
Seçime bağlı olarak gönderilecek argümanların türlerinin _"variadic"_ fonksiyon tarafından bilinmesi mümkün değildir. Derleyici seçimlik _(opsiyonel)_ argümanları işleve göndermeden "varsayılan argüman dönüşümü" _(default argument conversion)_ denilen dönüşümü gerçekleştirir. Yani _char_ ve _short_ türlerden olan argümanlar işaretli ya da işaretsiz _int_ türüne, _float_ türden olan argümanlar ise _double_ türüne dönüştürülürler. İstenilen sayıda argümanla çağrılan işlevlerin en zayıf tarafı da budur: Derleyicinin bir tür kontrolü yapma şansı yoktur. Bu yüzden _variadic_ işlevler normal işlevlere göre daha yüksek kodlama hatası riski içerirler.

#### stdarg.h başlık dosyası içinde tanımlanan makrolar
_variadic_ bir işlevin tanımlanabilmesi için standart _<stdarg.h>_ başlık dosyasında bildirilen _va_list_ türünün ve yine aynı başlık dosyasında tanımlanan bazı standart makroların kullanılması gerekmektedir:

#### va_list
_va_list_ opsiyonel argümanları gösterecek bir adres türüne verilen bir tür eş ismidir _(type alias)_. C Standartı _va_list_'in hangi türe bir _typedef_ bildirimi ile eş isim olarak seçileceğini derleyicilere bırakmıştır. Seçimlik argümanların dolaşılabilmesi için _va_list_ türünden bir değişkenin tanımlanması ve bu değişkene _va_start _makrosuyla değer verilmesi gerekir.

#### va_start
va_start aşağıdaki gibi bir makrodur:

```C
void va_start(va_list args, last_req);
```
Bu makro seçimlik argümanları dolaşma işleminde kullanılacak _va_list_ türünden değişkene değerini verir. 
Böylece _va_list_ türünden değişkenin seçimlik ilk argümanı göstermesi sağlanır. 
Makronun ikinci parametresine işlevin türü belirtilerek isimlendirilmiş son parametresinin isminin geçilmesi gerekir.

#### va_arg makrosu
```C
va_arg(va_list arg, arg_type);
```

_va_arg_ makrosu sıradaki seçimlik argümanın değerini döndürürken _va_list_ türünden değişkenin de değerini değiştirerek onun bir sonraki seçimlik argümanı göstermesini sağlar. Makronun ikinci parametresine elde edilecek argümanın tür bilgisinin geçilmesi gerekir. Bu makroya döngüsel bir yapıda, seçimlik argümanların sayısı kadar çağrı yapılmasıyla işlevin _variadic_ parametresine gönderilen tüm argümanlara erişilebilir.

#### va_end makrosu

```C
va_end(va_list ap);
```
Bu makro seçimlik argümanların dolaşılması sürecini sonlandırmak için çağrılır. _Variadic_ işlevin çalışacak kodunun sonlanmasından önce bu makronun çağrılması gerekir.

#### va_copy makrosu

```C
void va_copy(va_list dest, va_list source);
```
Bu makro dile _C99_ standartları ile eklenmiştir. ;
_va_start_ makrosu çağrılarak ilk değerini almış _va_list_ türünden değişkenin bu makro ile kopyası çıkartılabilir. 
Böylece fonksiyona gelen argümanları birden fazla kez dolaşmak kolayca mümkün hale gelir.

#### variadic parametreye gönderilen argümanların kullanılması
İşlevlerin normal parametre değişkenlerini isimleri yoluyla kullanabiliriz. 
Ancak _variadic_ parametreye ilişkin argümanların gönderildiği parametrelerin isimleri yoktur. 
Bu durumda işlev tanımında onları nasıl kullanacağız? 
İşleve gönderilen argümanlara yalnızca, standart _stdarg.h_ başlık dosyasında tanımlanan özel makroları kullanarak, fonksiyon çağrısı ile gönderildikleri sıra ile erişebiliriz. 
Standart _va_start_, _va_arg_ ve _va_end_ makrolarını kullanarak 3 aşamalı bir sürecin oluşturulması gerekir:

Önce _va_start_ makrosunu kullanarak _va_list_ türünden bir _pointer_ değişkene değer verilmelidir. 
Bu yapıldığında _va_list_ türünden değişken seçimlik ilk argümanı gösteriyor hale gelir. 
Daha sonra _va_arg_ makrosuna döngüsel bir yapıda çağrı yaparak tüm seçimlik argümanlara erişilebilir. 
Yani _va_arg_ makrosuna yapılan ilk çağrı ilk argümanı, ikinci çağrı ikinci argümanı verir. 
Argümanların hepsinin dolaşılması zorunlu değildir. 
İşleve gönderilen argümanların bir kısmına erişmemek herhangi bir şekilde tanımsız davranış oluşturmaz. 
Ancak gönderilen argüman sayısından daha fazla sayıda argümana erişim girişimi tanımsız davranıştır.

Argümanların elde edilmesi işleminin bitirildiğini ifade etmek için _va_list_ türünden değişken ile _va_end_ makrosuna çağrı yapılması gerekiyor.Aslında derleyicilerin çoğu va_end makrosu karşılığı hiçbir kod üretmiyor.Yine de hem standartlara tam olarak uygun bir kod oluşturmak için hem de kodun okunmasını kolaylaştırmak _va_end_ makrosu mutlaka çağrılmalı.

#### işlev tanımında seçimlik argümanların sayısının elde edilmesi
_variadic_ işlevlerde argüman sayısının elde edilmesi için birden fazla teknik kullanılabilir.
İşlevin tam sayı türünden bir parametresi _(tipik olarak birinci parametre)_ çağıran koddan işleve gönderilen diğer argümanların sayısını alır. Bu uygulanması en kolay tekniktir. Şimdi bu tekniği kullanan bir işlevi kodlayalım:

```C
#include <stdarg.h>
#include <stdio.h>
int sum(int count, ...)
{
    int sum = 0;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        sum += va_arg(args, int);
    }
    va_end(args);
    return sum;
}

int main(void)
{
    int a = sum(2, 15, 20);
    int b = sum(3, 10, 15, 20);
    int c = sum(4, a, b, 10, 10);
    printf("c = %d\n", c);
}
```

Yukarıdaki kodda tanımlanan _sum_ isimli _variadic_ işlev kendisine gönderilen tam sayıların toplamını hesaplıyor. Aşağıdaki kodda yine aynı tekniği kullanan _min_ ve _max_ isimli işlevlerin tanımları yer alıyor. Bu işlevler kendilerine gönderilen tam sayılardan en küçük ve en büyük olanlarının değerlerini hesaplar:

```C
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>

int min(int count, ...)
{
    int min = INT_MAX;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        int ival = va_arg(args, int);
        if (ival < min)
            min = ival;
    }
    va_end(args);
    return min;
}

int max(int count, ...)
{
    int max = INT_MIN;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        int ival = va_arg(args, int);
        if (ival > max)
            max = ival;
    }
    va_end(args);
    return max;
}

int main(void)
{
    int x, y, z, t;
    printf("dort sayi giriniz: ");
    scanf("%d%d%d%d", &x, &y, &z, &t);
    printf("min = %d\n", min(4, x, y, z, t));
    printf("max = %d\n", max(4, x, y, z, t));
}
```

Bir başka teknik _variadic_ işlevin kendisini çağıran koddan bir yazının adresini alarak kendisine gönderilen seçimlik argümanların sayısını bu yazıdan elde etmesidir. 
Örneğin _stdio_ kütüphanesinde bildirilen standart _scanf_ ve _printf_ işlevleri de bu tekniği kullanırlar. 
Aşağıda _printf_ işlevini sarmalayan basitleştirilmiş _print_ isimli bir işlev tanımlıyoruz:

```C
#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
void print(const char* pfmt, ...)
{
    va_list args;
    va_start(args, pfmt);
    while (*pfmt != '\0') {
        int ch = toupper(*pfmt);
        if (ch == 'D') {
            int i = va_arg(args, int);
            printf("%d\n", i);
        }
        else if (ch == 'C') {
            int c = va_arg(args, int);
            printf("%c\n", c);
        }
        else if (ch == 'F') {
            double d = va_arg(args, double);
            printf("%f\n", d);
        }
        else if (ch == 'U') {
            unsigned int uval = va_arg(args, unsigned int);
            printf("%u\n", uval);
        }
        ++pfmt;
    }
    va_end(args);
}

int main(void)
{
    print("DcFfu", 3, 'a', 1.999, 42.5, 98u);
}
```
Çağrıyı yapan kod, işleve son argüman olarak başka bir argüman gönderilmeyeceğini belirten özel bir değer gönderebilir. Aşağıdaki kodu inceleyelim :

```
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* concat(const char* ptr, ...)
{
    va_list args1, args2;
    va_start(args1, ptr);
    va_copy(args2, args1);
    const char* p;
    size_t len = strlen(ptr);
    while ((p = va_arg(args1, const char*)) != NULL)
        len += strlen(p);
    char* pd = (char*)malloc(len + 1);
    if (!pd) {
        fprintf(stderr, "bellek yetersiz\n");
        exit(EXIT_FAILURE);
    }
    va_end(args1);
    strcpy(pd, ptr);
    while ((p = va_arg(args2, const char*)) != NULL)
        strcat(pd, p);
    va_end(args2);

    return pd;
}

int main(void)
{
    char* p = concat("necati ", "ergin ", "kaan ", "aslan", NULL);
    puts(p);
    free(p);
}
```

Yukarıdaki kodda ismi _concat_ olan istenilen sayıda argümanla çağrılabilen bir işlev tanımlanıyor. _concat_ işlevi kendisine adresleri gönderilen yazıları elde ettiği dinamik bir bellek bloğunda birleştiriyor. İşlevi çağıran kod, birleştirilecek son yazının adresinden sonra işleve başka bir yazı gönderilmediğini bildirmek amacıyla işleve _NULL_ gösterici geçiyor.Yukarıdaki kodda _va_copy_ makrosunun kullanılması ile seçimlik argümanların iki kez dolaşıldığını görüyorsunuz.
