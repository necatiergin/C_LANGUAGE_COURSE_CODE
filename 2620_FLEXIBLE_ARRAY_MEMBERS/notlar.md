C99 standartlarıyla C diline eklenen öğelerden biri "yapıların esnek dizi öğeleri" _(flexible array members)_. Bir _flexible array_ bir yapı türünün son öğesi olarak olarak bildirilebiliyor:

```
struct Student{
	int no;
	int grades[];
};
```

Yukarıda örnekte _struct Student_ türünün ikinci ve son öğesinin boyut belirtilmeden bildirilen _grades_ isimli bir _int_ dizi _(incomplete array type)_ olduğunu görüyorsunuz. Yapının bu öğesi için bir yer _(storage)_ elde edilmediği sürece bu öğe yapı nesnesi içinde bir yer kaplamayacak. Aşağıdaki koda bakalım:

```
#include <stdio.h>
 
int main()
{
	printf("sizeof(int) = %zu\n", sizeof(int));
	printf("sizeof(struct Student) = %zu\n", sizeof(struct Student));
}
```
Kodu derleyip çalıştırdığınızda _sizeof(int)_ ve _sizeof(struct Student)_ değerlerinin aynı olduğunu göreceksiniz. _flexible array_ yapının son öğesi olmak zorunda. Örneğin aşağıdaki gibi bir bildirim geçersiz:

```
struct Student {
	int grades[]; //geçersiz
	int no;
};
```
Peki yapının bu esnek dizi öğesini nasıl kullanacağız? Bir struct Student nesnesinin bellek alanını dinamik bellek işlevleriyle elde ederek flexible array öğemizin boyutunu programın çalışma zamanında belirleyebiliriz:

```
#include <stdio.h>
#include <stdlib.h>
 
int main()
{
	size_t n;
	printf("kac not: ");
	scanf("%zu", &n);
 
	struct Student *p = (struct Student *)
		malloc(sizeof(struct Student) + n * sizeof(int));
	//...
}
```
Esnek dizi özelliği olmasaydı öğe olan _grades_ isimli dizinin boyutunu mümkün olduğunca büyük belirlemek zorunda kalacaktık:

```
#define MAX_NUMBER_OF_GRADES   20
 
struct Student {
	int no;
	int grades[MAX_NUMBER_OF_GRADES];
};
```
Yazacağımız kodda oluşturacağımız bazı struct Student nesneleri için muhtemelen, öğe olan dizinin yalnızca belirli sayıda elemanını kullanacağız. Bu da toplamda kullanılan bellek alanının gereksiz yere artması sonucunu doğuracak.

Yapıların esnek dizi öğelerine ilk değer verilemiyor. Aşağıdaki kod geçersiz:

```
struct Student {
	int no;
	int grades[];
};
 
int main()
{
	struct Student s = { 12, {1, 5, 6, 7} }; //geçersiz
}
```
Ancak birçok derleyici böyle bir nesne tanımlamasına bir eklenti _(extension)_ ile izin veriyor.

Esnek dizi öğesi içeren yapı nesneleri birbirine atama işleciyle atandığında esnek dizi öğeleri birbirine kopyalanmaz:

```
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
typedef struct {
	int age;
	char name[];
}Person;
 
int main()
{
	Person *p1 = (Person *)malloc(sizeof(Person) + 6);
	Person *p2 = (Person *)malloc(sizeof(Person) + 6);
	
	if (!p1 || !p2)
		return;
	p1->age = 35;
	strcpy(p1->name, "Kemal");
	p2->age = 45;
	strcpy(p2->name, "Murat");
 
	*p1 = *p2;
 
	printf("%d %s\n", p1->age, p1->name); //45 Kemal
	free(p1);
	free(p2);
}
```
Esnek dizi öğesinin kopyalanması için standart _strcpy_ ya da _memcpy_ işlevlerini çağırabiliriz.

Bu aracın _C99_ standartları ile dile eklenmesinden önce, esnek dizi öğesi kullanmak ancak derleyicinin sağladığı eklentilerle mümkündü. Derleyiciler tarafından sunulan tipik eklentilerden biri yapının son öğesinin boyutu _0_ olan bir dizi olarak bildirilebilmesiydi:

```
struct Student {
	int id;
	int grades[0];
};
```
