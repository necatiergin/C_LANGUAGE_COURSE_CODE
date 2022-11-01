C99 standartları ile C diline eklenen en önemli araçlardan biri compound literal. Türkçe karşılığı olarak bileşik sabit teriminin kullanılmasını öneriyorum.

C’de yazdığımız kodlarda sıklıkla şöyle bir durumla karşılaşıyoruz: Bir diziye, bir yapı (structure) ya da bir birlik (union) nesnesine ihtiyacımız var. Ancak söz konusu nesneyi muhtemelen yalnızca tek bir yerde kullanacağız. Bu durumda isimlendirilmiş bir değişken tanımlamamız gerekiyor. Aşağıdaki koda bakalım:

```
struct Rect{
    double e1, e2;
};
 
void draw_rect(struct Rect);
int foo(const int *p);
 
int main()
{
    struct Rect rec = { 1.2, 6.7 };
    int a[] = { 2, 6, 7, 1, 3 };
 
    draw_rect(rec);
    foo(a); 
}
```
main işlevi içinde tanımlanan rec ve a nesnelerinin yalnızca draw_rect ve foo işlevlerine yapılan çağrılarda kullanılmak için tanımlandığını düşünelim. Kod bu niyeti açıkça anlatmadığı için okuyucuyu da yanıltıyor. Ben böyle bir kodu okuduğumda bu nesnelerin kapsamları (scope) içinde tekrar kullanılacaklarını düşünüyorum. Bu tür kodlarda bir başka sorun da "kapsam sızıntısı" (scope leakage) yani bu isimlerin kapsamlarının gereksiz yere geniş tutulması. Bu isimler bir daha kullanılmayacak olsalar da kapsamları içinde yanlışlıkla isimlerinin yazılması bir kodlama hatasına neden olabilir.

Bir bileşik sabit kullanarak isimlendirilmemiş bir dizi, yapı ya da birlik nesnesi oluşturabiliriz:

```
int main()
{
    draw_rect((struct Rect){ 1.2, 6.7 });
    foo((int []) { 2, 6, 7, 1, 3 }); 
}
```
İşlevlere gönderdiğimiz argümanlar bileşik sabitler. Aslında struct Rect türünden bir yapı nesnesini ve 5 elemanlı bir int diziyi isim vermeden oluşturmuş olduk. Şimdi compound literal ifadelerine yönelik sentaksı ayrıntılarıyla ele almaya başlayabiliriz. Önce dizi oluşturan bileşik sabit ifadelerini inceleyelim: Sentaksta yer alması gereken parantez içine dönüşüm türünü (cast type) yazıyoruz. Bu oluşturulacak dizinin türü. Daha sonra küme parantezi içinde oluşturacağımız dizinin elemanlarına verdiğimiz ilk değerleri listeliyoruz. Örneğin:

```
(int [3]){1, 2, 3}
```
ifadesi ile 3 elemanlı bir int dizi oluşturmuş oluyoruz. Parantez içinde dizinin türünü belirtirken dizinin boyutunu yazabileceğimiz gibi boyut değerinin çıkarımını derleyiciye de bırakabiliyoruz:

```(int []){1, 2, 3, 4, 5, 6}```
Yukarıdaki ifade ile 6 elemanlı int bir dizi oluşturduk. Dizinin eleman sayısını belirtir ve eleman sayısından daha az sayıda ilk değer sağlarsak dizinin kalan elemanları varsayılan değerlerle (tam sayı ve gerçek sayı dizileri için 0, gösterici dizileri için NULL gösterici) hayata başlıyorlar:

```(double a[20]) {1., 2., 3.}```
ifadesi ile 20 elemanlı bir dizi oluşturarak dizinin ilk 3 elemanının alacağı değerleri belirtmiş olduk. Dizinin kalan 17 elemanı 0. değerleriyle hayata başlayacak. Dizi elemanlarına ilk değer verirken yine C99 standartlarıyla dile eklenen designated initializer denilen sentaks ile dizinin seçilmiş elemanlarına ilk değer verip diğer elemanlarını varsayılan değerlerle başlatabiliyoruz:

```(int [100]){[12] = 2, [34] = 4, [67] = 6}```
Yukarıdaki ifade ile 100 elemanlı bir dizi oluşturduk. dizinin sırasıyla 12, 34 ve 67 indeksli elemanlarına ilk değerlerini verdik ve kalan elemanlarının hayata 0 değerleriyle gelmesini sağladık. "designated initializer" kullanılması durumunda yine dizinin boyutunu belirtmek zorunda değiliz:

```(int []){[12] = 2, [34] = 4, [67] = 6}```
Yukarıdaki ifade ile bu kez 68 elemanlı bir dizi oluşturmuş olduk. Yapı ya da birlik nesnelerinin "compound literal" biçiminde oluşturulması için kullanılması gereken sentaks da neredeyse aynı. Employee isimli bir yapı türünün bildirildiğini düşünelim:

```typedef struct {
    char name[40];
    int id;
    double wage;
}Employee;```
Şimdi bu türden nesnelerin oluşturulmasını sağlayacak bazı "bileşik sabit" ifadeleri yazalım:

```(Employee){"Burhan Koc", 1345, 45.60)```
Yukarıdaki ifade ile Employee türünden bir nesneyi tüm elemanlarına ilk değer vererek oluşturduk.

(Employee){"Furkan Demirci")
Yukarıdaki ifadede ise oluşturduğumuz Employee nesnesinin yalnızca name isimli elemanına ilk değer verdik. Nesnemizin diğer elemanları 0 değerleri ile hayata başlamış oldu.

```(Employee){.id = 7651, .name = "Can Demirci")```
Yukarıdaki ifade de ise oluşturduğumuz Employee nesnesinin seçilmiş elemanlarına "designated initializer" sentaksı ile ilk değer verdik. Şimdi de aşağıdaki kodu inceleyelim:

```typedef struct
{
    const char *pname;
    int no;
} Student;
int main()
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
}```
Yukarıdaki kodda main işlevi içinde elemanları Student türünden boyutu 10 olan bir dizi tanımlanıyor ve dizinin belirlenmiş elemanlarına ilk değer veriliyor. Daha sonra dizinin 1 ve 2 indisli elemanlarına Student türünden bileşik sabit ifadeleri ile atamalar yapılıyor. Aynı türden yapı nesnelerinin birbirlerine atanabildiğini hatırlayalım.

Compound literal ifadeleri ile oluşturulan nesnelere sabit ifadeleri (constant expressions) ile ilk değer verme zorunluluğu yok:

```void f(int x, int y, int z)
{
    int *p = (int[]) { x, y, z };
    //...
}```
Yukarıda tanımlanan func işlevi içinde oluşturulan 3 elemanlı int diziye isimlendirilmemiş nesneye işlevin parametre değişkenleri ile ilk değer veriliyor. Diziden adrese dönüşüm (array to pointer conversion) kuralı burada da geçerli.

Bileşik sabit ifadeleri ile tekil (scalar) türlerden de nesneler oluşturmamız mümkün:

```void f()
{
    int *ip = &(int) { 10 };
    double *dp = &(double) { 12.3 };
    //...
}```
Yukarıdaki örneği yalnızca kodun geçerli olduğunu göstermek için verdim.

"literal" sözcüğü "sabit" anlamında kullanılsa da "compound literals" biçiminde oluşturulan nesnelerin değerlerini değiştirmek tanımlı (defined) davranış niteliğinde:

```#include <string.h>
int main()
{
    Employee *p = &(Employee) { .id = 7651 };
    strcpy(p->name, "Nurdan Temiz");
    p->wage = 45.80;
    //...
}```
Yukarıdaki örnekte oluşturulan Employee nesnesinin adresi ile p isimli gösterici değişkene ilk değer veriliyor. Daha sonraki deyimlerle nesnemizin name ve wage isimli elemanlarının değerlerinin değiştirildiğini görüyorsunuz. Bileşik sabit ifadeleri ile oluşturduğumuz dizileri de değiştirebiliriz:

```int main()
{
    int *p = (int[5]) { 0 };
    //...
    for (int i = 0; i < 5; ++i)
 	p[i] = i;
    //...
}```
Bu şekilde oluşturulan char türden dizilerde tutulan yazıları da değiştirebiliriz:

```int main()
{
    char *p = (char[]) { "Beyhan" };
    //...
    *p = 'S';
}```
Ancak bir bileşik sabit ifadesi ile const bir nesne de oluşturmamız mümkün:

```void display_employee(const Employee *p);
int main()
{
    const int *p = (const int[]) { 2, 3, 5, 7, 11, 13, 17, 19, 29 };
	//
    display_employee(&(const Employee) { "Nihat Uslu", 7121, 20.20 });
}```
Global kod alanında oluşturulan "bileşik sabit" nesneleri, diğer isimlendirilmiş global nesneler gibi statik ömür (static storage class) kategorisindeler. Blok içinde oluşturulan nesneler ise otomatik ömre (automatic storage class) sahipler:

```void f()
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
Yukarıda tanımlanan func işlevi içinde oluşturulan içsel blokta oluşturulan int türden otomatik ömürlü nesnemizin adresini p isimli bir gösterici değişkene atıyoruz. Otomatik ömürlü nesnenin hayatı oluşturulduğu kapsamı sonlandıran “}” atomunun bulunduğu yerde sona erecek. Bloğun dışındaki kodlar yürütüldüğünde artık nesnemiz hayatta olmadığı için p gösterici değişkeni bu durumda geçersiz (dangling) durumda. Şimdi de aşağıdaki koda bakalım:

```typedef struct {
    int mx, my;
}Point;
void drawpixel(Point);
void drawline()
{
    for (int i = 0; i < 10; ++i)
	drawpixel((Point) {i, i});
}```
Yukarıdaki kodda drawline işlevinin tanımında yer alan for döngüsünün her turunda yeni bir Point nesnesi oluşturuluyor. Böylece işlev (0,0) ve (9, 9) noktalarını birleştiren bir doğru çiziyor.

Bileşik Sabit ifadeleri sabit ifadesi kategorisinde olmadıkları için normal olarak statik ömürlü bir nesneye bir bileşik sabit ifadesi ile ilk değer vermemiz geçerli değil:

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
Yukarıdaki kodda foo içinde yapılan tanımlamaların hiçbiri geçerli değil. Ancak bir GNU eklentisiyle GCC derleyicisinde bu mümkün kılınmış. Bu eklenti kullanıldığında yukarıdaki tanımlamalar aşağıdaki gibi bir kodla aynı anlama geliyor:

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
Bileşik sabit ifadeleri C++ dilinin sentaksında yer almıyor. Ancak başta GCC olmak üzere birçok C++ derleyicisi bu özelliği bir eklenti (extension) olarak kullanıma sunuyor.
