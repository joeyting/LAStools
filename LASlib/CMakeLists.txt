project ( LAS )

# definitions for VC++
add_definitions( -DCOMPILE_AS_DLL  -D_CRT_SECURE_NO_WARNINGS )

add_definitions( -DUNORDERED )

include_directories( BEFORE ../LASzip/src inc  )

add_library( las SHARED
             src/lasreader.cpp src/laswriter.cpp src/lasreader_las.cpp src/lasreader_bin.cpp src/lasreader_qfit.cpp src/lasreader_shp.cpp src/lasreader_asc.cpp src/lasreader_bil.cpp src/lasreader_dtm.cpp src/lasreader_txt.cpp src/lasreadermerged.cpp src/lasreaderbuffered.cpp src/lasreaderpipeon.cpp src/laswriter_las.cpp src/laswriter_bin.cpp src/laswriter_qfit.cpp src/laswriter_wrl.cpp src/laswriter_txt.cpp src/laswritercompatible.cpp src/laswaveform13reader.cpp src/laswaveform13writer.cpp src/lasutility.cpp src/lasfilter.cpp src/lastransform.cpp src/fopen_compressed.cpp 
../LASzip/src/laszip.cpp ../LASzip/src/lasreadpoint.cpp ../LASzip/src/lasreaditemcompressed_v1.cpp ../LASzip/src/lasreaditemcompressed_v2.cpp ../LASzip/src/laswritepoint.cpp  ../LASzip/src/laswriteitemcompressed_v1.cpp ../LASzip/src/laswriteitemcompressed_v2.cpp ../LASzip/src/integercompressor.cpp ../LASzip/src/arithmeticdecoder.cpp ../LASzip/src/arithmeticencoder.cpp ../LASzip/src/arithmeticmodel.cpp ../LASzip/src/lasindex.cpp ../LASzip/src/lasquadtree.cpp ../LASzip/src/lasinterval.cpp )

install(TARGETS las
        LIBRARY DESTINATION lib)
install(DIRECTORY inc/ DESTINATION include/LASlib
        FILES_MATCHING PATTERN "*.hpp")
install(DIRECTORY ../LASzip/src/ DESTINATION include/LASzip
        FILES_MATCHING PATTERN "*.hpp")

