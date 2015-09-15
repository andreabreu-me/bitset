# bitset
Реализация битового множества (аналог std::bitset)

## Известные ошибки

## Органичения

## Тесты производительности

## Требования
* CMake version 3.3.2
* git version 1.8.3.1
* gcc version 4.8.3

## Установка CMake

На момент сборки стабиьная версия CMake 3.3.2
```
mkdir /opt/cmake
cd /opt/cmake
curl https://cmake.org/files/v3.3/cmake-3.3.2-Linux-x86_64.sh > cmake-3.3.2-Linux-x86_64.sh
sh cmake-3.3.2-Linux-x86_64.sh
```

## Сборка проекта
```
cd ~
git clone https://github.com/russkin/bitset.git
cd bitset
mkdir build
cd build
/opt/cmake/bin/cmake ..
make
make test
```
## TODO
* Контроль выхода за границы массива
* Динамически расширяемое множество

## License MIT
