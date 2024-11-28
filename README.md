Tamamen Fonksiyonel programlama  fnPi dilini derlemek için aşağıdaki liste gerekli özelliklere sahiptir:
 1: Lexer.h
 2: Parse.h
 3: Semantic.h
 4: IRGenerator.h
 5: Optimizer.h
 6: CodeEmiter.h
 7: MemoryManager.h
 8: RuntimeEnvi.h
 9: Debugging.h
10: Performance.h
11: fnPicomp.cpp

kütüphane Kendisini derlemek için gerekli tüm fonksiyon ve metotları içermelidir.
12: library/ klasör 
13: kütüphane oluştur. örnek: std.lib, io.lib, math.lib, memory.lib, string.lib, files.lib, sqlite.lib ...

14: piCom.exe // oluştur.
15: example.pi // derle....




Lexer (Lexical Analyzer): 
Kelime analizi algoritması
Özel kelime anahtarları ve semboller tanımlaması
Kod bloğu ayrıştırma
Comment ve string parsing

Parser: 
Gramer kuralları
AST (Abstract Syntax Tree) yapısı
Sözdizimi kontrolü ve hata ayıklama

Semantic Analyser: 
Tiplendirme ve tür kontrolü
Bağlam kontrolü
Hata ayıklama ve uyarılar

Intermediate Representation (IR) Generator: 
AST'yi IR koduna çevirme
Optimizasyon için gerekli bilgiler saklama

Optimizer: 
Kod hareketi
Redundans eliminasyonu
Sabit ifade değerlendirme
Değerlendirme optimizasyonu

Runtime Environment:
Standart kütüphane modülleri
Sistem çağrıları
Hata yönetimi

Debugging Support:
Hata mesajları ve konumlandırma bilgileri
Debugging modu

Code Emitter: 
IR kodu makine koduna çevirme
Register tahsisatı
Bellek yönetimi
Bellek tahsisi ve serbest bırakma
Kontrol akışı optimizasyonu

Performance Profiling:
Zaman ve bellek profili
Optimizasyon önerileri


Bu bileşenler, fnpi dilini derlemek için gerekli temel yapıyı oluşturacaktır. 
