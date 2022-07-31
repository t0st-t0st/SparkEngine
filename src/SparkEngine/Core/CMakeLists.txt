set(LIB_NAME Core)

set(INCROOT ${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}/${LIB_NAME})
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/${PROJECT_NAME}/${LIB_NAME})

set(SRC
    ${INCROOT}/Export.hpp

    ${INCROOT}/Vector2.hpp
    ${INCROOT}/Vector2.inl
    ${SRCROOT}/Vector2.cpp

    ${INCROOT}/Dll.hpp
    ${SRCROOT}/Dll.cpp

    ${INCROOT}/Window.hpp
    ${SRCROOT}/Window.cpp
    ${SRCROOT}/WindowImpl.hpp
	${SRCROOT}/WindowImpl.cpp
)
source_group("" FILES ${SRC})

set(FRAMEWORK_SRC
    ${INCROOT}/Framework/ApplicationLayer.hpp
    ${SRCROOT}/Framework/ApplicationLayer.cpp
)
source_group("Framework" FILES ${FRAMEWORK_SRC})

if(WIN32)
    set(PLATFORM_SRC 
	  ${SRCROOT}/Platform/Win32/WindowImplWin32.hpp
	  ${SRCROOT}/Platform/Win32/WindowImplWin32.cpp
    )
    source_group("Platform" FILES ${PLATFORM_SRC})
endif()

add_library(${LIB_NAME} SHARED ${SRC} ${PLATFORM_SRC} ${FRAMEWORK_SRC})
set_property(TARGET ${LIB_NAME} PROPERTY FOLDER "SparkEngine")
set_target_properties(${LIB_NAME} PROPERTIES LINKER_LANGUAGE CXX)

set_property(TARGET ${LIB_NAME} PROPERTY CXX_STANDARD 17)
set_property(TARGET ${LIB_NAME} PROPERTY DEFINE_SYMBOL CORE_EXPORTS)

target_include_directories(${LIB_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(${LIB_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/src)