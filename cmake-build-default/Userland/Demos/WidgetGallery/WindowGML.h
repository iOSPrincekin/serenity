extern const char window_gml[];
const char window_gml[] = R"~~~(@GUI::Widget {
    fill_with_background_color: true
    layout: @GUI::VerticalBoxLayout {
        margins: [4]
    }

    @GUI::TabWidget {
        name: "tab_widget"
        reorder_allowed: true
    }
}
)~~~";
