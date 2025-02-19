serenity_component(
    Browser
    RECOMMENDED
    TARGETS Browser
    DEPENDS BrowserSettings ImageDecoder RequestServer WebContent WebSocket
)

compile_ipc(WebDriverSessionServer.ipc WebDriverSessionServerEndpoint.h)
compile_ipc(WebDriverSessionClient.ipc WebDriverSessionClientEndpoint.h)

compile_gml(BrowserWindow.gml BrowserWindowGML.h browser_window_gml)
compile_gml(EditBookmark.gml EditBookmarkGML.h edit_bookmark_gml)
compile_gml(StorageWidget.gml StorageWidgetGML.h storage_widget_gml)
compile_gml(Tab.gml TabGML.h tab_gml)

set(SOURCES
    BookmarksBarWidget.cpp
    BrowserWindow.cpp
    ConsoleWidget.cpp
    CookieJar.cpp
    CookiesModel.cpp
    DownloadWidget.cpp
    ElementSizePreviewWidget.cpp
    History.cpp
    IconBag.cpp
    InspectorWidget.cpp
    StorageModel.cpp
    StorageWidget.cpp
    Tab.cpp
    WebDriverConnection.cpp
    WindowActions.cpp
    main.cpp
)

set(GENERATED_SOURCES
    BrowserWindowGML.h
    EditBookmarkGML.h
    StorageWidgetGML.h
    TabGML.h
    WebDriverSessionClientEndpoint.h
    WebDriverSessionServerEndpoint.h
)

serenity_app(Browser ICON app-browser)
target_link_libraries(Browser PRIVATE LibCore LibWebView LibWeb LibProtocol LibGUI LibDesktop LibConfig LibGfx LibIPC LibJS LibLocale LibMain LibSyntax)
link_with_locale_data(Browser)
