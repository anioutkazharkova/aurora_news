import QtQuick 2.0
import Sailfish.Silica 1.0
import CustomCppClasses.Module 1.0

Page {
    objectName: "newItemPage"
    allowedOrientations: Orientation.All
    property NewsItemVM viewModel
    onViewModelChanged: { }

Connections {
    target: viewModel
    onNewsItemLoaded: {
        image.source = viewModel.urlToImage
        lblContent.text = viewModel.content
        lblDate.text = viewModel.publishedAt
        lblTitle.text = viewModel.title
        header.title = qsTr(viewModel.title)
        link.plainText = viewModel.url
    }
}

    SilicaFlickable {
     anchors.fill: parent
     PageHeader {
         id: header
     }
        Image {
            id: image
            horizontalAlignment: Image.AlignHCenter
             fillMode: Image.PreserveAspectFit
            asynchronous: true
            anchors.top: header.bottom
    anchors.left: parent.left
    anchors.right: parent.right
            width: parent.width
            height: 500
        }
        LinkedLabel {
            id:link
            defaultLinkActions: true
            anchors.top: image.bottom
            anchors.topMargin: 20
            anchors.leftMargin: 10
            anchors.rightMargin: 10
            anchors.left: parent.left
            anchors.right: parent.right
        }

        Text {
            id: lblTitle
            anchors.top: link.bottom
            anchors.topMargin: 20
            anchors.leftMargin: 10
            anchors.rightMargin: 10
            anchors.left: parent.left
            anchors.right: parent.right
            wrapMode: Text.WordWrap
            maximumLineCount: 5
            color: Theme.primaryColor
            x: Theme.horizontalPageMargin
font { pointSize: 24; bold: true }
        }
        Text {
            id: lblContent
            anchors.top: lblTitle.bottom
            anchors.topMargin: 20
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.leftMargin: 10
            anchors.rightMargin: 10
            wrapMode: Text.WordWrap
            color: Theme.primaryColor
            x: Theme.horizontalPageMargin
font { pointSize: 18;}
        }
        Text {
            id: lblDate
            anchors.top: lblContent.bottom
            anchors.topMargin: 20
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.leftMargin: 10
            anchors.rightMargin: 10
            wrapMode: Text.WordWrap
            color: Theme.primaryColor
            x: Theme.horizontalPageMargin
font { pointSize: 14;}
        }
    }
    Component.onCompleted: {
         viewModel.start()
    }
}
