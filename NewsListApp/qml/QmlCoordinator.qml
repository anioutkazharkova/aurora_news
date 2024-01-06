import QtQuick 2.0
import Sailfish.Silica 1.0
import CustomCppClasses.Module 1.0
Item {
    property PageStack pageStack
property DIProvider diProvider
    property string newsListPage:  "pages/NewsListPage.qml"
    property string newsItemPage: "pages/NewsItemPage.qml"

    function pushPageWithVm(path, vm) {
        return pageStack.push(instantiatePage(path), {"viewModel": vm})
    }

    function replaceAllPagesWithPageAndVm(path, vm) {
        return pageStack.replaceAbove(null, instantiatePage(path), {"viewModel": vm})
    }

    function popCurrentPage() {
        pageStack.pop()
    }

    function instantiatePage(path) {
        return Qt.createComponent(Qt.resolvedUrl(path))
    }
}
