cmake_minimum_required(VERSION 3.25)
project(AnimationProgramming)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME}
        main.cpp
        src/applications/Application.h
        src/opengl/Attribute.cpp
        src/opengl/Attribute.h
        src/opengl/Uniform.cpp
        src/opengl/Uniform.h
        src/opengl/IndexBuffer.cpp
        src/opengl/IndexBuffer.h
        src/opengl/VertexArray.cpp
        src/opengl/VertexArray.h
        src/opengl/Shader.cpp
        src/opengl/Shader.h
        src/opengl/Draw.cpp
        src/opengl/Draw.h
        src/opengl/Texture.cpp
        src/opengl/Texture.h
        src/applications/TriangleApp.cpp
        src/applications/TriangleApp.h
        )

# ==== for downloading submodules automatically ====
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    # Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/glfw/CMakeLists.txt")
    message(FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/glm/CMakeLists.txt")
    message(FATAL_ERROR "The submodules were not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()
# ==== ========================================= ====


add_subdirectory(external/glad)
add_subdirectory(external/glfw)
add_subdirectory(external/glm)
add_subdirectory(external/stb_image)
add_subdirectory(external/cgltf)

target_link_libraries(${PROJECT_NAME}
        PRIVATE glad glfw glm stb_image cgltf)

# Apparently you dont need these?
#target_include_directories(${PROJECT_NAME}
#        PUBLIC external/glfw/include)
#target_link_directories(${PROJECT_NAME}
#        PUBLIC external/glfw/src)

#target_link_directories(${PROJECT_NAME}
#        PRIVATE ${CMAKE_SOURCE_DIR}/external/glad/)
#target_link_libraries(${PROJECT_NAME}
#        PRIVATE glad)