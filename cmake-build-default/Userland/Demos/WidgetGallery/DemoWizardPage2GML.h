extern const char demo_wizard_page_2_gml[];
const char demo_wizard_page_2_gml[] = R"~~~(@GUI::Widget {
    layout: @GUI::VerticalBoxLayout {
        margins: [20]
    }

    @GUI::Label {
        text: "Please wait..."
        text_alignment: "TopLeft"
        fixed_height: 32
    }

    @GUI::Progressbar {
        name: "page_2_progressbar"
        fixed_height: 28
    }

    // Spacer
    @GUI::Widget {}
}
)~~~";
