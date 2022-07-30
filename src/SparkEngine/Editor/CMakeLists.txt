set(LIB_NAME Editor)

set(INCROOT ${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}/${LIB_NAME})
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/${PROJECT_NAME}/${LIB_NAME})

set(SRC
    ${INCROOT}/EditorLayer.hpp
    ${SRCROOT}/EditorLayer.cpp
)
source_group("" FILES ${SRC})

add_library(${LIB_NAME} SHARED ${SRC})
set_property(TARGET ${LIB_NAME} PROPERTY FOLDER "SparkEngine")
set_target_properties(${LIB_NAME} PROPERTIES LINKER_LANGUAGE CXX)

set_property(TARGET ${LIB_NAME} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${LIB_NAME} PROPERTY DEFINE_SYMBOL EDITOR_EXPORTS)

target_include_directories(${LIB_NAME} PUBLIC  ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(${LIB_NAME} PRIVATE Core)

