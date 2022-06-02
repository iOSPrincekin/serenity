extern const char cursors_tab_gml[];
const char cursors_tab_gml[] = R"~~~(@GUI::Widget {
    name: "cursors_tab"
    layout: @GUI::VerticalBoxLayout {
        margins: [4]
    }

    @GUI::GroupBox {
        layout: @GUI::VerticalBoxLayout {
            margins: [6]
        }

        @GUI::TableView {
            name: "cursors_tableview"
            font_size: 12
        }
    }
}
)~~~";
