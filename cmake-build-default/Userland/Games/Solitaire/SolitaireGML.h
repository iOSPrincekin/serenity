extern const char solitaire_gml[];
const char solitaire_gml[] = R"~~~(@GUI::Widget {
    fill_with_background_color: true
    layout: @GUI::VerticalBoxLayout {}

    @Solitaire::Game {
        name: "game"
        fill_with_background_color: true
        background_color: "green"
    }

    @GUI::Statusbar {
        name: "statusbar"
        segment_count: 3
    }
}
)~~~";
