set(SOURCES
    Color/ColorConverter.cpp
    Color/ColorPrimaries.cpp
    Color/TransferCharacteristics.cpp
    MatroskaDemuxer.cpp
    MatroskaReader.cpp
    PlaybackManager.cpp
    VideoFrame.cpp
    VP9/BitStream.cpp
    VP9/Decoder.cpp
    VP9/Parser.cpp
    VP9/ProbabilityTables.cpp
    VP9/SyntaxElementCounter.cpp
    VP9/TreeParser.cpp
)

serenity_lib(LibVideo video)
target_link_libraries(LibVideo PRIVATE LibAudio LibCore LibIPC LibGfx)
