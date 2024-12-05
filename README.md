# OOP 7 ЛР

## Вариант 1
Модифицируйте вашу лабораторную работу №6 следующим образом: 
- Должно быть реализовано три потока: 
  - Поток, который осуществляет передвижение NPC на определенное расстояние (см. таблицу), а также определяет, что два NPC находятся на расстоянии убийства (см. таблицу). 
  - Если два NPC вступили в «бой», то он создает задачу для потока, осуществляющего бои. 
  - Поток, который осуществляет бои. Если один npc может убивать другой, то каждый npc «кидает 6-гранный кубик» определяя силу атаки и силу защиты (соответственно). Если сила атаки больше, чем сила защиты – то происходит убийство. 
 - Мертвые npc не передвигаются (у нас тут без некромантов). 
 - Живые npc не могут покинуть карту (размер задается через константы, например 100  x 100) 
 - Основной поток раз в секунду печатает карту. Мертвые npc на карте не отображаются. 
 - Осуществить контроль доступа к разделяемым ресурсов с помощью std::shared_lock и std::lock_guard 
 - Осуществить контроль к потоку вывода std::cout через std::lock_guard 
 - Потоки могут запускаться как std::thread с использованием лямбда функций или функторов (классов с перегруженным оператором operator()) 
 - Вначале игры должно создаваться 50 npc в случайных локациях. 
 - Игра должна останавливаться через 30 секунд и выводить на экран список выживших 

Усложненный вариант (+10 очков к максимальному балу): 
 - Реализовать перемещение и сражение NPC в одном потоке, используя coroutine. 
 - Основной поток, так же должен будет выводить данные о карте на экран

Таблица убиваемости:
| Кто нагоняет | Расстояние хода | Расстояние убийства |
|--------------|-----------------|---------------------|
| Орк          | 20              | 10                  |
| Белка        | 5               | 5                   |
| Друид        | 10              | 10                  |


Вариант 1. 
Объекты: Орк, Белка, Друид
Правило совместимости: 
 - Орки убивают друидов  
 - Друиды убивают Белок 
 - Белки за мир 

## Инструкция по запуску
1. **Склонируйте ветку с лабой и откройте в VS Code**
    ```bash
   git clone -b lr7 https://github.com/mihateren/oop.git
   cd oop
   code oop
    ```
2. **Сборка через Dev Container**
    Установите расширение [Dev Containers](vscode:extension/ms-vscode-remote.remote-containers).
    
3. **Откройте проект в Dev Container**
    Нажмите F1 или Ctrl+Shift+P для открытия палитры команд.
    Введите Dev Containers: Reopen in Container и выберите этот пункт.

4. **Сборка и запуск проекта в контейнере**
    После того как контейнер будет готов, откройте терминал в VS Code и перейдите в папку build и выполните команды:
    ```bash
    cd build
    make
    ```
5. **Выполните команды для запуска проекта**
    Для запуска программы введите:
        ```
        ./lr7
        ```\
    Для запуска юнит-тестов введите:
        ```
        ./tests
        ```