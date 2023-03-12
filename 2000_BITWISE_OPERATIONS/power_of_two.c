#define power_of_two(a)      ((a) && !((a) & ((a) - 1)))

/*
    Bir tam sayıyı bir eksiği ile bitsel ve işlemine tabi tutarsak sağdan ilk bir bitini sıfırlamış oluruz.
    2'nin kuvveti olan sayılar yalnzca tek bir biti 0 olan sayılardır. 
    2'nin kuvveti olan bir sayıyı bir eksiği ile bitsel ve işlemine sokarsak 0 değerini elde etmeliyiz.
    Ancak 2'nin kuvveti olmamasına rağmen 0, bir sayıyla bitsel ve işlemine sokulduğunda 0 değeri elde edilir.
  
*/

