
// первичное наполнение данными структуры "об_нагрузка_оперсист" для создания новой точки
// часть данных переносится в разряд "СТАРЫХ" а часть данных сбрасывается в ноль
int f_об_нагрузка_оперсист_нов_точка(void);


// функция по наполнению объекта "нагрузка операционной системы" данными по работе SSD диска
int f_блок_нагрузки_ssd(void);


// функция по наполнению объекта "нагрузка операционной системы" данными по температуре первого ядра процессора (самого горячего)
int f_блок_температура_cpu(void);


// функция по наполнению объекта "нагрузка операционной системы" данными
int f_нагрузка_пк(void);


// программа определяем стколько ядер всего у процессора в системе
// всего (реальные + виртуальные)
int f_cpuinfo(void);


// функция по наполнению объекта "нагрузка операционной системы" данными использованию перативной памяти
int f_блок_использование_ram(void);
    // программа определяем стколько памяти (оперативной и SWAP) у нас на ПК
    // всего, занято, свободно, в том числе занято SWAP памятью
    // используем proc/meminfo
    // *1) MemTotal     ВСЕГО RAM
    // *2)MemFree       полностью свободна (даже не зарезервированна)Память, которая нигде не используется
    // 3)MemAvailable   Доступна (в том числе кэши + буферы, резервированная)
    // *4)Buffers       буферы
    // *5)Cached        кэш то что зарезервированно программами, так PostgreSQL занимает 9 Гб, даже не работая!!!)
    // 6)SwapCached     перенесено в Swap диск из оперативки на жеский диск)
    // 13) Unevictable  Память, выделенная для пользовательского пространства, которая не может быть освобождена
    // 14) Mlocked      Память, заблокированная с помощью    mlock()
    // *15) SwapTotal   общий размер СВОП памяти
    // *16) SwapFree    Свободная СВОП память
    // 19) Dirty        Память, ожидающей обратной записи на диск
    // 20) WriteBack    Память, которая активно записывается обратно на диск
    // 21) AnonPages    Страницы пользовательского пространства (не файлы, а оперативка). 
    //                  Чем больше открываешь программ, тем больше чисо в этом поле.
    // 23) Shmem        Общий размер памяти, используемой общей памятью (типа память занятая системой, ядром)
    //                  При болшом количестве открытых программ, это значение практически не меняется.
    // 40) AnonHugePages Таблица больших пользователских пространств. Чем больше открываешь файлов, тем больше здесь число


// функция по расчету промежуточных значений с интервалами от 1 до 15 секунд
// эти значения записываются в структуру с данными и при наступлении контрольных точек - скидываются в БД в таблицу
int f_промежуточые_значения(void); 










