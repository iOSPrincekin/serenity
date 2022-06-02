    .file "/Users/lee/Desktop/Computer_Systems/serenity/cmake-build-default/Userland/Demos/ModelGallery/ModelGallery-serenity_icon_s.s"
    .data
    .section serenity_icon_s, "a", @progbits
    .align 4
    .globl serenity_icon_s_start
    .type serenity_icon_s_start, @object
    .size serenity_icon_s_start, 4
serenity_icon_s_start:
    .incbin "/Users/lee/Desktop/Computer_Systems/serenity/Base/res/icons/16x16/app-model-gallery.png"
    .section serenity_embedded_resource_info, "a", @progbits
    .align 4
    .globl serenity_icon_s_size
    .type serenity_icon_s_size, @object
    .size serenity_icon_s_size, 4
serenity_icon_s_size:
    .long 694

