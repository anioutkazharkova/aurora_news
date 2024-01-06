import QtQuick 2.0
import CustomCppClasses.Module 1.0
import Sailfish.Silica 1.0
QmlCoordinator {
   //
    function openNewsItem(newsItem) {
        var vm = diProvider.getNewsItemVM(newsItem)
pushPageWithVm(newsItemPage,vm)
    }

    function openNews() {
        var vm = diProvider.getNewsListVM()
        vm.openNewsItem.connect(openNewsItem)
        pushPageWithVm(newsListPage, vm)
    }
}
