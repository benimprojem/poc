Tamamen Fonksiyonel programlama  fnPi dilini derlemek için aşağıdaki liste gerekli özelliklere sahip olması gerekli:

A: Lexer (Lexical Analyzer): Lexer.h
	1: Kelime analizi algoritması
	2: Özel kelime anahtarları ve semboller tanımlaması
	3: Kod bloğu ayrıştırma
	4: Comment ve string parsing

B: Parser: Parser.h 
	1: Gramer kuralları
	2: AST (Abstract Syntax Tree) yapısı
	3: Sözdizimi kontrolü ve hata ayıklama

C: Semantic Analyser:  Semantic.h
	1: Tiplendirme ve tür kontrolü
	2: Bağlam kontrolü
	3: Hata ayıklama ve uyarılar

D: Intermediate Representation (IR) Generator:  IRGenerator.h
	1: AST'yi IR koduna çevirme
	2: Optimizasyon için gerekli bilgiler saklama

E: Optimizer:  Optimizer.h
	1: Kod hareketi
	2: Redundans eliminasyonu
	3: Sabit ifade değerlendirme
	4: Değerlendirme optimizasyonu

F: Runtime Environment:  RuntimeEnvi.h
	1: Standart kütüphane modülleri
	2: Sistem çağrıları
	3: Hata yönetimi

G: Memory Manager:  MemoryManager.h

H: Debugging Support: Debugging.h
	1: Hata mesajları ve konumlandırma bilgileri
	2: Debugging modu

I: Code Emitter:
	1: IR kodu makine koduna çevirme
	2: Register tahsisatı
	3: Bellek tahsisi ve serbest bırakma
	4: Kontrol akışı optimizasyonu

J: Performance Profiling: Performance.h
	1: Zaman ve bellek profili
	2: Optimizasyon önerileri
	
	
K: fnpicom.cpp

kütüphane Kendisini derlemek için gerekli tüm fonksiyon ve metotları içermelidir.
L: library/ klasör 
 kütüphane oluştur. örnek: std.lib, io.lib, math.lib, memory.lib, string.lib, files.lib, sqlite.lib ...

M: fnpicom.exe // oluştur.
N: example.pi // derle....


fnpi Dilinin yapısı aşağıda örneklenmiştir. Bazı fonksiyonlar eksik olabilir.
verilen örneklere göre eklenmelidir.

Operatörler

"" 
in 
not in
not 
between
is
is not
at 
as


%	expr % expr	Aritmetik kalan	Rem
%=	var %= expr	Aritmetik kalan ve atama	RemAssign

*	expr * expr	Aritmetik çarpma	Mul
*=	var *= expr	Aritmetik çarpma ve atama	MulAssign	
+	trait + trait,'a + trait	Bileşik tip kısıtlaması	
+	expr + expr	Aritmetik toplama	Add
/	expr / expr	Aritmetik bölme	Div
/=	var /= expr	Aritmetik bölme ve atama	DivAssign
++  expr++ Aritmetik toplama bir ekle	Add expr+1
+=	var += expr	Aritmetik toplama ve atama	AddAssign	
-	- expr	Aritmetik olumsuzlama	Neg
-	expr - expr	Aritmetik çıkarma	Sub
--  expr-- Aritmetik çıkarma bir çıkarma	Sub expr-1
-=	var -= expr	Aritmetik çıkarma ve atama	SubAssign

&&	expr && expr	Mantıksal VE'yi kısa devre yapma

||	expr || expr	Mantıksal VEYA'yı kısa devre yapma	
&	expr & expr	Bitsel VE	BitAnd
&=	var &= expr	Bit düzeyinde VE ve atama	BitAndAssign
!	!expr	"not" Bit düzeyinde veya mantıksal tamamlayıcı

&	&type, &mut type, &'a type,&'a mut type	Ödünç alınan işaretçi türü	
*	*expr	Referanstan çıkarma	Deref
*	*const type,*mut type pointer Ham işaretçi	

,	expr, expr	Argüman ve eleman ayırıcı
;	expr;	Beyan ve madde sonlandırıcı	
	

=	var = expr; , ident = type;	Görev/denklik	
!=	expr != expr	Eşitsizlik karşılaştırması	PartialEq
==	expr == expr	Eşitlik karşılaştırması	PartialEq

>	expr > expr	Karşılaştırmadan daha büyük	PartialOrd
>=	expr >= expr  Karşılaştırmadan büyük veya eşit	PartialOrd
<	expr < expr	Karşılaştırmadan daha az	PartialOrd
<=	expr <= expr	Karşılaştırmadan küçük veya eşit	PartialOrd

	


>>	expr >> expr	Sağa kaydırma	Shr
>>=	var >>= expr	Sağa kaydırma ve atama	ShrAssign
<<	expr << expr	Sola kaydırma	Shl
<<=	var <<= expr	Sola kaydırma ve atama	ShlAssign

?	expr?	Hata yayılımı



data type : belirtilmemişse rakamlar için i32 otomatik alır.
örnek:
8 bit	i8	 u8	 	f8
16 bit	i16	 u16 	f16
32 bit	i32  u32 	f32
64 bit	i64	 u64	f64
128 bit	i128 u128	f128

	   -int  int	float
örnek =	-5	 12		12.35 

const- sabit öğeleri veya sabit ham işaretçileri tanımlayın
örnek:
const u32: THREE_HOURS_IN_SECONDS = (60 * 60 * 3);

static- tüm program yürütmesi boyunca süren küresel değişken veya yaşam süresi
static: a = 25;

let- bir değişkeni bağla
örnek:
let char: a = "ℤ"; // a değişkeni "char" 1 karakter tutar.


true- 1 Boolean gerçek değeri
false- 0 Boolean yanlış değişmezi

type- bir tür takma adı veya ilişkili tür tanımlayın
enum- bir numaralandırma tanımla


if- koşullu bir ifadenin sonucuna göre dallanma 
els- geri dönüş 
örnek:
if:condition{
  // block of code to be executed if the condition is true
}els:{
  // block of code to be executed if the condition is false
}

elsif - kontrol akışı yapıları
örnek:
if:condition1 {
	// block of code to be executed if condition1 is true
} elsif:condition2{
	// block of code to be executed if the condition1 is false and condition2 is true
} els: {
	// block of code to be executed if the condition1 is false and condition2 is false
}

print- 
func carp:a,b{return a*b;}
a=10;
print:"bu sayı: :ret/ dur. ",nl(carp:a,5;);


for- 
örnek:
i8 a=5;
for: i=0, i < a, i++{
	print: i, nl;
}

foreach- array için döngü
örnek: 
foreach: arr, row{
	// code block
}


while- bir ifadenin sonucuna göre koşullu döngü
örnek:
while: condition{
	// code block
}


loop- koşulsuz döngü

match- bir değeri desenlerle eşleştir

continue- bir sonraki döngü yinelemesine devam et
örnek:
for:i = 0; i < 10; i++ {
	if: i == 4 {
		print:"Seçilen sayı: :i: ", nl; 
		// :i: ise değişken olarak tanımlanmış i nin değerini ifade eder ve 
		// type otomatik çevrilir. :data: datanın type ne olduğu önemli değildir ve her zaman print içerisinde türü otomatik çevrilir.
		// eğer "" ile ifade edilmiş bir string yoksa ve direkt değişken kullanılacaksa sadece i yeterli olur.
		// ,nl her zaman ekrana basılan string den sonra yeni satıra geçer. Yoksa geçmez. 
		continue;
	}
	print: i, nl;
}

break- döngüden hemen çık.
örnek:
for:i = 0; i < 10; i++ {
	if:i == 4 {
		print:"Seçilen :nl: sayısı bulundu: :i:"; 
		// string içinde :nl: yeni satıra geçer 
		// :i: ise değişken olarak tanımlanmış i nin değerini ifade eder
		break;
	}
	print:i, nl;
}


switch- bir anahtar kelimeye ulaştığında " }" switch bloğundan çıkar.
örnek:
switch:expression(
	case: x{
		// code block
	}
	case: y{
		// code block
	}
	def:{
		// code block
	}
);



-:	func(...) -: type,|…| -> type	Fonksiyon ve kapanış dönüş tipi	


func- bir fonksiyon veya fonksiyon işaretçisi türünü tanımlayın
return- fonksiyondan dönüş
örnek:
tanımlama:
func topla:a,b,c{
	//.....
	d = a+b+c;
	return d;
}

kullanmı: 
t = topla:1,6,5;
print: t; 
// print: t,nl;

array- 
let myNumbers i32 = [25, 50, 75, 100];
length = arrlen: myNumbers; // dizideki eleman sayısı
myNumbers.push: 22; // myNumbers dizisine 22 sayısını ekle


import- kütüphane import etmek için 
örnek:
import: math.lib, std.lib, .... ;

typeof-
örnek: 
typeof: "John Doe";     // Returns "string"
typeof: 0;              // Returns "number"
typeof: 314;            // Returns "number"
typeof: 3.14;           // Returns "number"
typeof: (3);            // Returns "number"
typeof: (3 + 4);        // Returns "number"


pointers-
myAge = 43;     // An variable
*ptr = &myAge;  // A pointer variable, with the name ptr, that stores the address of myAge




struct- bir yapı tanımla
//crate- bir modül yolunda, sandık köküne atıfta bulunur
örnek:
struct str {
  // code block  tüm modların kullanacağı değişkenleri tanımladığımız yer
  len: { // code block }
  slice: { // code block }
  trim: { // code block }
  at: { // code block }
}
a = str.len: text; // text değişkenindeki stringin karakter sayısını verir. 


string- Tüm string ler UTF8 kodlaması kullanır.
str.modül: 
str.len:
str:trim:
str.at:-2


bellek yönetimi c dekinin aynısı olacak..


main-  ilk çalışan ana fonksiyon
main: {
	// code block
}



json-
objdata = json.objpar: jsonfile;  // json ile gelen verileri "object" nesneye çevirir. 
arrdata = json.arrpar: jsonfile;  // json ile gelen verileri "array" diziye çevirir. 
jsonfile= json.convert: arrdata;  // array daki verileri json a çevirir. 





await- a'nın sonucu Future hazır olana kadar yürütmeyi askıya al

dyn- bir özellik nesnesine dinamik gönderim

union- bir birleşim tanımlayın ; yalnızca birleşim bildiriminde kullanıldığında bir anahtar sözcüktür
impl- doğal veya özellik işlevselliğini uygulamak
infor- döngü sözdiziminin bir parçası
extern- harici bir fonksiyonu veya değişkeni bağlayın

mod- bir modül tanımla
move- bir kapanış yapın, tüm yakalamalarının mülkiyetini alın
mut- referanslarda, ham işaretçilerde veya desen bağlamalarında değişebilirliği belirtin
pub- yapı alanlarında, implbloklarda veya modüllerde genel görünürlüğü belirtin
ref- referansla bağla


Self- tanımladığımız veya uyguladığımız tür için bir tür takma adı

self- yöntem konusu veya geçerli modül

super- geçerli modülün üst modülü
trait- bir özelliği tanımla


unsafe- güvenli olmayan kodları, işlevleri, özellikleri veya uygulamaları belirtmek
use- sembolleri kapsama dahil etmek

where- bir türü kısıtlayan ifadeleri belirtir





g++ -o fnpi Main.cpp fnpi_compiler.cpp Lexer.cpp Parser.cpp MemoryManager.cpp StringModule.cpp