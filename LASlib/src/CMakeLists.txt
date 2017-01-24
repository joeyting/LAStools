project ( LAS )

# definitions for VC++
add_definitions( -DCOMPILE_AS_DLL  -D_CRT_SECURE_NO_WARNINGS )

add_definitions( -DUNORDERED )

include_directories( BEFORE ../../LASzip/src ../inc  )

                     

add_library( las SHARED
             lasreader.cpp laswriter.cpp lasreader_las.cpp lasreader_bin.cpp lasreader_qfit.cpp lasreader_shp.cpp lasreader_asc.cpp lasreader_bil.cpp lasreader_dtm.cpp lasreader_txt.cpp lasreadermerged.cpp lasreaderbuffered.cpp lasreaderpipeon.cpp laswriter_las.cpp laswriter_bin.cpp laswriter_qfit.cpp laswriter_wrl.cpp laswriter_txt.cpp laswritercompatible.cpp laswaveform13reader.cpp laswaveform13writer.cpp lasutility.cpp lasfilter.cpp lastransform.cpp fopen_compressed.cpp 
../../LASzip/src/laszip.cpp ../../LASzip/src/lasreadpoint.cpp ../../LASzip/src/lasreaditemcompressed_v1.cpp ../../LASzip/src/lasreaditemcompressed_v2.cpp ../../LASzip/src/laswritepoint.cpp  ../../LASzip/src/laswriteitemcompressed_v1.cpp ../../LASzip/src/laswriteitemcompressed_v2.cpp ../../LASzip/src/integercompressor.cpp ../../LASzip/src/arithmeticdecoder.cpp ../../LASzip/src/arithmeticencoder.cpp ../../LASzip/src/arithmeticmodel.cpp ../../LASzip/src/lasindex.cpp ../../LASzip/src/lasquadtree.cpp ../../LASzip/src/lasinterval.cpp )
