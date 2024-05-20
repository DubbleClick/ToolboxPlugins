include_guard()
include(FetchContent)

# Fetch gwtooolboxpp using FetchContent
FetchContent_Declare(
  gwtoolboxpp
  GIT_REPOSITORY https://github.com/gwdevhub/gwtoolboxpp
  GIT_TAG dev
)

FetchContent_GetProperties(gwtoolboxpp)

if(gwtooolboxpp_POPULATED)
    message(STATUS "Skipping gwtooolboxpp download")
    return()
endif()

FetchContent_Populate(gwtoolboxpp)

add_compile_definitions(GWCA_CTOS_ENABLED=0)
add_subdirectory(${gwtoolboxpp_SOURCE_DIR} EXCLUDE_FROM_ALL)
