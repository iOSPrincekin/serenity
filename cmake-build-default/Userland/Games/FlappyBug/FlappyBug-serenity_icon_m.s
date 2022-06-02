    .file "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Games/FlappyBug/FlappyBug-serenity_icon_m.s"
    .data
    .section serenity_icon_m, "a", @progbits
    .align 4
    .globl serenity_icon_m_start
    .type serenity_icon_m_start, @object
    .size serenity_icon_m_start, 4
serenity_icon_m_start:
    .incbin "/Users/lee/Desktop/Computer_Systems/serenity/Base/res/icons/32x32/app-flappybug.png"
    .section serenity_embedded_resource_info, "a", @progbits
    .align 4
    .globl serenity_icon_m_size
    .type serenity_icon_m_size, @object
    .size serenity_icon_m_size, 4
serenity_icon_m_size:
    .long 279

