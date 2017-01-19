project ( LAStools )

include_directories (BEFORE ../LASlib/inc ../LASzip/src )

# definitions for VC++
add_definitions ( -DUSE_AS_DLL -D_CRT_SECURE_NO_WARNINGS )

find_library ( LAS_LIBRARY las HINTS ../LASlib/src/VC12 )


add_executable ( las2las las2las.cpp geoprojectionconverter.cpp )
target_link_libraries( las2las ${LAS_LIBRARY} )

add_executable ( las2txt las2txt.cpp )
target_link_libraries( las2txt ${LAS_LIBRARY} )

add_executable ( txt2las txt2las.cpp geoprojectionconverter.cpp )
target_link_libraries( txt2las ${LAS_LIBRARY} )

add_executable ( lasmerge lasmerge.cpp geoprojectionconverter.cpp )
target_link_libraries( lasmerge  ${LAS_LIBRARY} )

add_executable ( lasoptimize lasoptimize.cpp geoprojectionconverter.cpp  )
target_link_libraries( lasoptimize  ${LAS_LIBRARY} )

add_executable ( lasindex lasindex.cpp   )
target_link_libraries( lasindex  ${LAS_LIBRARY} )

add_executable ( lasinfo lasinfo.cpp geoprojectionconverter.cpp  )
target_link_libraries( lasinfo  ${LAS_LIBRARY} )

add_executable ( lasdiff lasdiff.cpp   )
target_link_libraries( lasdiff  ${LAS_LIBRARY} )

add_executable ( lasprecision lasprecision.cpp geoprojectionconverter.cpp  )
target_link_libraries( lasprecision  ${LAS_LIBRARY} )
