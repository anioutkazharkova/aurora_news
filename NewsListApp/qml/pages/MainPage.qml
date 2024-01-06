/*******************************************************************************
**
** Copyright (C) 2022 ru.auroraos
**
** This file is part of the Моё приложение для ОС Аврора project.
**
** Redistribution and use in source and binary forms,
** with or without modification, are permitted provided
** that the following conditions are met:
**
** * Redistributions of source code must retain the above copyright notice,
**   this list of conditions and the following disclaimer.
** * Redistributions in binary form must reproduce the above copyright notice,
**   this list of conditions and the following disclaimer
**   in the documentation and/or other materials provided with the distribution.
** * Neither the name of the copyright holder nor the names of its contributors
**   may be used to endorse or promote products derived from this software
**   without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
** AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
** THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
** FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
** IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
** FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
** OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
** PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
** LOSS OF USE, DATA, OR PROFITS;
** OR BUSINESS INTERRUPTION)
** HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
** WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE)
** ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
** EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
*******************************************************************************/

import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    objectName: "mainPage"
    allowedOrientations: Orientation.All

    SilicaListView {
                   anchors.fill: parent

                   header: Column {
                       width: parent.width
                       height: header.height + mainColumn.height + Theme.paddingLarge

                       PageHeader {
                           id: header
                           title: "Пример Аврора"
                       }

                       Column {
                           id: mainColumn
                           width: parent.width
                           spacing: Theme.paddingLarge

                           Slider {
                               id: slider
                               label: "Простой ползунок"
                               width: parent.width
                               minimumValue: 0; maximumValue: 100; stepSize: 1
                               valueText: value
                           }

                           Button {
                               text: "Сохранить"
                               anchors.horizontalCenter: parent.horizontalCenter
                               onClicked: {
                                   listModel.append({"sliderValue": "Value: " + slider.value})
                               }
                           }
                       }
                   }

                   model: ListModel { id: listModel }

                   delegate: ListItem {
                       id: listEntry
                       width: parent.width

                       Label {
                           color: listEntry.highlighted ? Theme.highlightColor : Theme.primaryColor
                           text: model.sliderValue
                           x: Theme.horizontalPageMargin
                           anchors.verticalCenter: parent.verticalCenter
                       }

                       menu: ContextMenu {
                           MenuItem {
                               text: "Удалить"
                               onClicked: {
                                   listEntry.remorseAction("Удаление", function() {
                                       listModel.remove(model.index)
                                   })
                               }
                           }
                       }
                   }

                   PullDownMenu {
                       MenuItem {
                           text: "Очистить"
                           onClicked: listModel.clear()
                       }
                   }

                   VerticalScrollDecorator {}
               }
  }

