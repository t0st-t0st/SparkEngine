set(APP_NAME Runtime)

set(INCROOT ${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}/${APP_NAME})
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/${PROJECT_NAME}/${APP_NAME})

set(SRC
    ${SRCROOT}/Main.cpp
)
source_group("" FILES ${SRC})

add_executable(${APP_NAME} ${SRC})
set_property(TARGET ${APP_NAME} PROPERTY FOLDER "SparkEngine")
set_target_properties(${APP_NAME} PROPERTIES LINKER_LANGUAGE CXX)

set_property(TARGET ${APP_NAME} PROPERTY CXX_STANDARD 17)

target_include_directories(${APP_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(${APP_NAME} PRIVATE Core)