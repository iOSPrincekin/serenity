extern const char icons_tab_gml[];
const char icons_tab_gml[] = R"~~~(@GUI::Widget {
    name: "icons_tab"
    layout: @GUI::VerticalBoxLayout {
        margins: [4]
    }

    @GUI::GroupBox {
        layout: @GUI::VerticalBoxLayout {
            margins: [6]
        }

        @GUI::TableView {
            name: "icons_tableview"
            font_size: 12
        }
    }
}
)~~~";
