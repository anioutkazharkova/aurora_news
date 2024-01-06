import QtQuick 2.0
import Sailfish.Silica 1.0
import CustomCppClasses.Module 1.0

Page {
    function onItemClick(item) {
        viewModel.openNewsItem(item)
    }

    objectName: "mainPage"
    allowedOrientations: Orientation.All
    property NewsListVM viewModel

    SilicaFlickable {
        anchors.fill: parent
        anchors.bottom: parent.bottom
                  anchors.top: parent.top
                  PageHeader {
                      id: pageHeader
                      objectName: "pageHeader"
                      title: qsTr("News List")
                      extraContent.children: [
                          TextField {
                              anchors.top:pageHeader.bottom
                              anchors.bottom: parent.bottom
                              anchors.left: parent.left
                              anchors.right: parent.right
                          width: parent.width
                          placeholderText: qsTr("Enter query")
                          id:queryField
                          EnterKey.iconSource: "image://theme/icon-m-enter-next"
                          EnterKey.onClicked: {
                             viewModel.loadNews(text)
                              focus = false
                          }
                          }
                      ]
                  }

   ListView {
      anchors.top: pageHeader.bottom
      anchors.bottom: parent.bottom
      anchors.left: parent.left
      anchors.right: parent.right
                   model: viewModel
                   delegate: ListItem {
                       onClicked: {
onItemClick(model)
                       }

width: parent.width
height: 280
Image {
    anchors.top: parent.top
    anchors.topMargin: 5
    anchors.leftMargin: 10
    anchors.rightMargin: 10
    anchors.left: parent.left
   id: image
   verticalAlignment: Image.AlignTop
   fillMode: Image.PreserveAspectCrop
   width: parent.width/3
   height: parent.width/3
source: model.urlToImage
asynchronous: true
}
                       Text{
                           id: lblTitle
                           anchors.top: parent.top
                           anchors.left: image.right
                           anchors.right: parent.right
                           anchors.rightMargin: 10
                           maximumLineCount : 2
                           wrapMode: Text.WordWrap
                           color: Theme.primaryColor
                           text: model.title
                           x: Theme.horizontalPageMargin
font { pointSize: 22; bold: true }
                       }
                       Text {
                           id: lblContent
                           anchors.top: lblTitle.bottom
                           anchors.topMargin: 5
                           anchors.left: image.right
                           anchors.right: parent.right
                           anchors.rightMargin: 10
                           maximumLineCount : 3
                           wrapMode: Text.WordWrap
                           color: Theme.primaryColor
                           text: model.content
                           //textFormat: Text.RichText
                           elide: Text.ElideRight
                           x: Theme.horizontalPageMargin
                           //lineHeightMode:Text.FixedHeight
                           font.pointSize: 18
                       }
                      Text {
                           id: lblDate
                           anchors.top: lblContent.bottom
                           anchors.bottom: parent.bottom
                           anchors.topMargin: 5
                           anchors.bottomMargin: 5
                           anchors.left: image.right
                           anchors.right: parent.right
                           maximumLineCount : 1
                           color: "gray"
                           text: model.publishedAt
                           font.pointSize: 14
                       }

                   }
}
    }
    Component.onCompleted: {
viewModel.loadNews("tesla")
}
}
