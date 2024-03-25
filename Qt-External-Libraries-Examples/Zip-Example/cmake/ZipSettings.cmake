#
# Функция архивирования файлов с 7-Zip.exe
#

function(archive_files_with_7zip archive_name files)

    find_program(ZIP_EXECUTABLE 7z PATHS "$ENV{ProgramFiles}/7-Zip")

    if(ZIP_EXECUTABLE)
        execute_process(COMMAND ${ZIP_EXECUTABLE} a -tzip "${archive_name}" ${CMAKE_SOURCE_DIR}/${files})
    elseif(ZIP_EXECUTABLE)
        message(FATAL_ERROR "7-zip program was not found")
    endif(ZIP_EXECUTABLE)

endfunction()
