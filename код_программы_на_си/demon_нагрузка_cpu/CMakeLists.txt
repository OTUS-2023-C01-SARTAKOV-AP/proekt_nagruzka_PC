cmake_minimum_required(VERSION 3.13)


# 		глобальное имя вашего проекта
project (nagruzka_pc_log_indb VERSION 23.12 LANGUAGES C)

#Set (NAME_PROGRAM  "main_nagruzka_cpu")	# как обозвать ваш файл на выходе (название программы) Русские буквы не принимает!
message(STATUS "имя проекта: ${PROJECT_NAME}") # Русские буквы - не принимает! не скомпилирует!!!!

Set (CMAKE_C_STANDAT 17)
Set (CMAKE_C_STANDART_REQUIRED True)


Set (BINARY_DIR "../../")
Set (CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BINARY_DIR}/это_программа/сборка_v_${CMAKE_PROJECT_VERSION}/запуск")
Set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "${BINARY_DIR}/это_программа/сборка_v_${CMAKE_PROJECT_VERSION}/lib")
Set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${BINARY_DIR}/это_программа/сборка_v_${CMAKE_PROJECT_VERSION}/lib")


message(STATUS "Начинаем компоновку и сборку программы версии = ${CMAKE_PROJECT_VERSION}")
message(STATUS "Корневой каталог для сборки: ${CMAKE_BINARY_DIR}")



# папки с нашим кодом проекта
add_subdirectory(main_program)
add_subdirectory(бд_запросы)
add_subdirectory(блок_нагрузка_пк)
add_subdirectory(настр_ключи_при_запуске)
add_subdirectory(ошибки_обработка)
add_subdirectory(системные_команды)
add_subdirectory(файлы_внешние)



find_package(PostgreSQL)
	# Found PostgreSQL: /usr/lib/x86_64-linux-gnu/libpq.so (found version "16.0") 
message(STATUS "Пакет/испол_модуль для PostgreSQL для сборки: ${PostgreSQL_LIBRARIES}\n")

# Добавляем заголовочный файл библиотеки  <libpq-fe.h> он же потом указывает на исполняемый модуль для
   # сборки: /usr/lib/x86_64-linux-gnu/libpq.so, но его указываем позже ОТДЕЛЬНО в блоке = arget_link_libraries(...)
include_directories(/usr/include/postgresql) # include <libpq-fe.h> OK





# ПЕРВОЕ имя должно быть именем из предыдущей строки(от main.c)
target_link_libraries(${PROJECT_NAME} PUBLIC zaprosi_in_db modul_nagruzka vhodn_dannie obrobotka_error system_comand files_work ${PostgreSQL_LIBRARIES}) 
	# для библиотеки PostgreSQL (самый последний в списке файлов в строчке выше) так же можно указать = pq -> это библиотека запросов для pq-fe.h   =	 target_link_libraries(${PROJECT_NAME} PUBLIC zaprosi_in_db ... pq) # где pq это библиотека запросов для pq-fe.h


# дополнительные параметры при компиляции 
add_compile_options(-Wall -Wextra -Wpedantic) # -g  -gdwarf2 -O2 

