extern const char character_search_window_gml[];
const char character_search_window_gml[] = R"~~~(@GUI::Frame {
    layout: @GUI::VerticalBoxLayout {}
    fill_with_background_color: true

    @GUI::Toolbar {
        @GUI::TextBox {
            name: "search_input"
        }

        @GUI::Button {
            name: "search_button"
            icon: "/res/icons/16x16/find.png"
            fixed_width: 22
        }
    }

    @GUI::TableView {
        name: "results_table"
    }
}
)~~~";
