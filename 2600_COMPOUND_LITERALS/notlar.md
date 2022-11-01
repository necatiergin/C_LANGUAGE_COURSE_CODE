_C99_ standartları ile _C_ diline eklenen en önemli araçlardan biri **compound literal**. Türkçe karşılığı olarak _"bileşik sabit"_ teriminin kullanılmasını öneriyorum.

C’de yazdığımız kodlarda sıklıkla şöyle bir durumla karşılaşıyoruz: Bir diziye, bir yapı _(structure)_ ya da bir birlik _(union)_ nesnesine ihtiyacımız var. Ancak söz konusu nesneyi muhtemelen yalnızca tek bir yerde kullanacağız. Bu durumda isimlendirilmiş bir değişken tanımlamamız gerekiyor. Aşağıdaki koda bakalım:

```
struct Rect{
    double e1, e2;
};
 
void draw_rect(struct Rect);
int foo(const int *p);
 
int main(void)
{
    struct Rect rec = { 1.2, 6.7 };
    int a[] = { 2, 6, 7, 1, 3 };
 
    draw_rect(rec);
    foo(a); 
}
```
_main_ işlevi içinde tanımlanan _rec_ ve _a_ nesnelerinin yalnızca _draw_rect_ ve _foo_ işlevlerine yapılan çağrılarda kullanılmak için tanımlandığını düşünelim. Kod bu niyeti açıkça anlatmadığı için okuyucuyu da yanıltıyor. Ben böyle bir kodu okuduğumda bu nesnelerin kapsamları (scope) içinde tekrar kullanılacaklarını düşünüyorum. Bu tür kodlarda bir başka sorun da "kapsam sızıntısı" _(scope leakage)_ yani bu isimlerin kapsamlarının gereksiz yere geniş tutulması. Bu isimler bir daha kullanılmayacak olsalar da kapsamları içinde yanlışlıkla isimlerinin yazılması bir kodlama hatasına neden olabilir.

Bir bileşik sabit kullanarak isimlendirilmemiş bir dizi, yapı ya da birlik nesnesi oluşturabiliriz:

```
int main(void)
{
    draw_rect((struct Rect){ 1.2, 6.7 });
    foo((int []) { 2, 6, 7, 1, 3 }); 
}
```
İşlevlere gönderdiğimiz argümanlar bileşik sabitler. Aslında _struct Rect_ türünden bir yapı nesnesini ve _5_ elemanlı bir _int_ diziyi isim vermeden oluşturmuş olduk. Şimdi _compound literal_ ifadelerine yönelik sentaksı ayrıntılarıyla ele almaya başlayabiliriz. Önce dizi oluşturan bileşik sabit ifadelerini inceleyelim: Sentaksta yer alması gereken parantez içine dönüşüm türünü _(cast type)_ yazıyoruz. Bu oluşturulacak dizinin türü. Daha sonra küme parantezi içinde oluşturacağımız dizinin elemanlarına verdiğimiz ilk değerleri listeliyoruz. Örneğin:

```
(int [3]){1, 2, 3}
```
ifadesi ile _3_ elemanlı bir int dizi oluşturmuş oluyoruz. Parantez içinde dizinin türünü belirtirken dizinin boyutunu yazabileceğimiz gibi boyut değerinin çıkarımını derleyiciye de bırakabiliyoruz:

```
(int []){1, 2, 3, 4, 5, 6}
```
Yukarıdaki ifade ile _6_ elemanlı _int_ bir dizi oluşturduk. Dizinin eleman sayısını belirtir ve eleman sayısından daha az sayıda ilk değer sağlarsak dizinin kalan elemanları varsayılan değerlerle (tam sayı ve gerçek sayı dizileri için _0_, gösterici dizileri için _NULL_ gösterici) hayata başlıyorlar:

```
(double a[20]) {1., 2., 3.}
```

ifadesi ile _20_ elemanlı bir dizi oluşturarak dizinin ilk I elemanının alacağı değerleri belirtmiş olduk. Dizinin kalan _17_ elemanı 0. değerleriyle hayata başlayacak. Dizi elemanlarına ilk değer verirken yine _C99_ standartlarıyla dile eklenen _"designated initializer"_ denilen sentaks ile dizinin seçilmiş elemanlarına ilk değer verip diğer elemanlarını varsayılan değerlerle başlatabiliyoruz:

```
(int [100]){[12] = 2, [34] = 4, [67] = 6}
```

Yukarıdaki ifade ile _100_ elemanlı bir dizi oluşturduk. Dizinin sırasıyla _12_, _34_ ve _67_ indeksli elemanlarına ilk değerlerini verdik ve kalan elemanlarının hayata 0 değerleriyle gelmesini sağladık. _"designated initializer"_ kullanılması durumunda yine dizinin boyutunu belirtmek zorunda değiliz:

```
(int []){[12] = 2, [34] = 4, [67] = 6}
```
Yukarıdaki ifade ile bu kez _68_ elemanlı bir dizi oluşturmuş olduk. Yapı ya da birlik nesnelerinin _"compound literal"_ biçiminde oluşturulması için kullanılması gereken sentaks da neredeyse aynı. _Employee_ isimli bir yapı türünün bildirildiğini düşünelim:

```
typedef struct {
    char name[40];
    int id;
    double wage;
}Employee;
```

Şimdi bu türden nesnelerin oluşturulmasını sağlayacak bazı _"bileşik sabit"_ ifadeleri yazalım:

```
(Employee){"Burhan Koc", 1345, 45.60)
```
Yukarıdaki ifade ile _Employee_ türünden bir nesneyi tüm elemanlarına ilk değer vererek oluşturduk.

```
(Employee){"Furkan Demirci")
```
Yukarıdaki ifadede ise oluşturduğumuz _Employee_ nesnesinin yalnızca _name_ isimli elemanına ilk değer verdik. Nesnemizin diğer elemanları _0_ değerleri ile hayata başlamış oldu.

```
(Employee){.id = 7651, .name = "Can Demirci")
```
Yukarıdaki ifade de ise oluşturduğumuz _Employee_ nesnesinin seçilmiş elemanlarına _"designated initializer"_ sentaksı ile ilk değer verdik. Şimdi de aşağıdaki kodu inceleyelim:

```
typedef struct
{
    const char *pname;
    int no;
} Student;

int main(void)
{
    Student a[] = { 
	[0].pname = "Metin", [0].no = 13, 
	[5].pname = "Sade", [0].no = 21,
	[7].pname = "Kagan", [0].no = 34,
	[9].pname = "Aleyna",[0].no = 77,
	};
	//...
    a[1] = (Student) { "Seher", 45 };
    a[2] = (Student) { "Cihan", 98 };
    //...
}
```

Yukarıdaki kodda _main_ işlevi içinde elemanları _Student_ türünden boyutu _10_ olan bir dizi tanımlanıyor ve dizinin belirlenmiş elemanlarına ilk değer veriliyor. Daha sonra dizinin 1 ve 2 indisli elemanlarına Student türünden bileşik sabit ifadeleri ile atamalar yapılıyor. Aynı türden yapı nesnelerinin birbirlerine atanabildiğini hatırlayalım.

_Compound literal_ ifadeleri ile oluşturulan nesnelere sabit ifadeleri _(constant expressions)_ ile ilk değer verme zorunluluğu yok:

```
void f(int x, int y, int z)
{
    int *p = (int[]) { x, y, z };
    //...
}
```
Yukarıda tanımlanan _func_ işlevi içinde oluşturulan _3_ elemanlı _int_ diziye isimlendirilmemiş nesneye işlevin parametre değişkenleri ile ilk değer veriliyor. Diziden adrese dönüşüm _(array decay)_ kuralı burada da geçerli.

Bileşik sabit ifadeleri ile tekil _(scalar)_ türlerden de nesneler oluşturmamız mümkün:

```
void f(void)
{
    int *ip = &(int) { 10 };
    double *dp = &(double) { 12.3 };
    //...
}
```
Yukarıdaki örneği yalnızca kodun geçerli olduğunu göstermek için verdim.

"literal" sözcüğü "sabit" anlamında kullanılsa da "compound literals" biçiminde oluşturulan nesnelerin değerlerini değiştirmek tanımlı _(defined)_ davranış niteliğinde:

```
#include <string.h>
int main(void)
{
    Employee *p = &(Employee) { .id = 7651 };
    strcpy(p->name, "Nurdan Temiz");
    p->wage = 45.80;
    //...
}
```
Yukarıdaki örnekte oluşturulan _Employee_ nesnesinin adresi ile _p_ isimli gösterici değişkene ilk değer veriliyor. Daha sonraki deyimlerle nesnemizin _name_ ve _wage_ isimli elemanlarının değerlerinin değiştirildiğini görüyorsunuz. Bileşik sabit ifadeleri ile oluşturduğumuz dizileri de değiştirebiliriz:

```
int main(void)
{
    int *p = (int[5]) { 0 };
    //...
    for (int i = 0; i < 5; ++i)
 	p[i] = i;
    //...
}
```
Bu şekilde oluşturulan char türden dizilerde tutulan yazıları da değiştirebiliriz:

```
int main(void)
{
    char *p = (char[]) { "Beyhan" };
    //...
    *p = 'S';
}
```
Ancak bir bileşik sabit ifadesi ile const bir nesne de oluşturmamız mümkün:

```
void display_employee(const Employee *p);
int main(void)
{
    const int *p = (const int[]) { 2, 3, 5, 7, 11, 13, 17, 19, 29 };
	//
    display_employee(&(const Employee) { "Nihat Uslu", 7121, 20.20 });
}
```

Global kod alanında oluşturulan _"bileşik sabit"_ nesneleri, diğer isimlendirilmiş global nesneler gibi statik ömür _(static storage class)_ kategorisindeler. Blok içinde oluşturulan nesneler ise otomatik ömre _(automatic storage class)_ sahipler:

```
void f(void)
{
    int *p;
    extern int func(void);
    {
 	p = &(int) { func() };
	*p = 1;   //sorun yok
    }
    // p pointer değişkeni dangling durumda.
	
    *p = 2;   //tanımsız davranış
}
```
Yukarıda tanımlanan _func_ işlevi içinde oluşturulan içsel blokta oluşturulan int türden otomatik ömürlü nesnemizin adresini _p_ isimli bir gösterici değişkene atıyoruz. Otomatik ömürlü nesnenin hayatı oluşturulduğu kapsamı sonlandıran _“}”_ atomunun bulunduğu yerde sona erecek. Bloğun dışındaki kodlar yürütüldüğünde artık nesnemiz hayatta olmadığı için _p_ gösterici değişkeni bu durumda geçersiz _(dangling)_ durumda. Şimdi de aşağıdaki koda bakalım:

```
typedef struct {
    int mx, my;
}Point;
void drawpixel(Point);
void drawline(void)
{
    for (int i = 0; i < 10; ++i)
	drawpixel((Point) {i, i});
}
```

Yukarıdaki kodda drawline işlevinin tanımında yer alan for döngüsünün her turunda yeni bir Point nesnesi oluşturuluyor. Böylece işlev (0,0) ve (9, 9) noktalarını birleştiren bir doğru çiziyor.

Bileşik Sabit ifadeleri sabit ifadesi kategorisinde olmadıkları için normal olarak statik ömürlü bir nesneye bir bileşik sabit ifadesi ile ilk değer vermemiz geçerli değil:

```
struct Point {
	int mx, my;
};
void foo()
{
    static struct Point p = (struct Point) { 1, 3 };
    static int y[] = (int[]) { 1, 2, 3 };
    static int z[] = (int[3]) { 1 };
    //...
}
```
Yukarıdaki kodda _foo_ işlevi içinde yapılan tanımlamaların hiçbiri geçerli değil. Ancak bir _GNU_ eklentisiyle _GCC_ derleyicisinde bu mümkün kılınmış. Bu eklenti kullanıldığında yukarıdaki tanımlamalar aşağıdaki gibi bir kodla aynı anlama geliyor:

```
struct Point {
    int mx, my;
};
void foo()
{
    static struct Point p = { 1, 3 };
    static int y[] = { 1, 2, 3 };
    static int z[] = { 1, 0, 0 };
    //...
}
```
Bileşik sabit ifadeleri _C++_ dilinin sentaksında yer almıyor. Ancak başta _GCC_ olmak üzere birçok _C++_ derleyicisi bu özelliği bir eklenti _(extension)_ olarak kullanıma sunuyor.
