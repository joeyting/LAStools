project ( LAS )

cmake_minimum_required(VERSION 2.8.11)

# definitions for VC++
add_definitions( -DCOMPILE_AS_DLL  -D_CRT_SECURE_NO_WARNINGS )

add_definitions( -DUNORDERED )

include_directories( BEFORE LASzip/src LASlib/inc  )

add_library( las SHARED
             LASlib/src/lasreader.cpp LASlib/src/laswriter.cpp LASlib/src/lasreader_las.cpp LASlib/src/lasreader_bin.cpp LASlib/src/lasreader_qfit.cpp LASlib/src/lasreader_shp.cpp LASlib/src/lasreader_asc.cpp LASlib/src/lasreader_bil.cpp LASlib/src/lasreader_dtm.cpp LASlib/src/lasreader_txt.cpp LASlib/src/lasreadermerged.cpp LASlib/src/lasreaderbuffered.cpp LASlib/src/lasreaderpipeon.cpp LASlib/src/laswriter_las.cpp LASlib/src/laswriter_bin.cpp LASlib/src/laswriter_qfit.cpp LASlib/src/laswriter_wrl.cpp LASlib/src/laswriter_txt.cpp LASlib/src/laswritercompatible.cpp LASlib/src/laswaveform13reader.cpp LASlib/src/laswaveform13writer.cpp LASlib/src/lasutility.cpp LASlib/src/lasfilter.cpp LASlib/src/lastransform.cpp LASlib/src/fopen_compressed.cpp 
LASzip/src/laszip.cpp LASzip/src/lasreadpoint.cpp LASzip/src/lasreaditemcompressed_v1.cpp LASzip/src/lasreaditemcompressed_v2.cpp LASzip/src/laswritepoint.cpp  LASzip/src/laswriteitemcompressed_v1.cpp LASzip/src/laswriteitemcompressed_v2.cpp LASzip/src/integercompressor.cpp LASzip/src/arithmeticdecoder.cpp LASzip/src/arithmeticencoder.cpp LASzip/src/arithmeticmodel.cpp LASzip/src/lasindex.cpp LASzip/src/lasquadtree.cpp LASzip/src/lasinterval.cpp )

install(TARGETS las
        LIBRARY DESTINATION lib)
install(DIRECTORY LASlib/inc/ DESTINATION include/LASlib
        FILES_MATCHING PATTERN "*.hpp")
install(DIRECTORY LASzip/src/ DESTINATION include/LASzip
        FILES_MATCHING PATTERN "*.hpp")

