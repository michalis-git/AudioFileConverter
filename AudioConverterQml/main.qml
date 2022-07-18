import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

Window {
  width: 640
  height: 480
  visible: true
  title: qsTr("App")

  ColumnLayout {
    RowLayout {
      TextInput {
        Layout.minimumWidth: 150
//        displayText: "please type a path"
      }
      RoundButton {
        text: qsTr("Load...")
        onClicked: console.log("Load button clicked")
      }
    }

    GroupBox {
        title: qsTr("Properties")
        ColumnLayout {
            anchors.fill: parent
            ComboBox {  }
            ComboBox {  }
            ComboBox {  }
        }
    }

    CheckBox { text: qsTr("Normalise") }

    RoundButton {
      font.bold: true
      text: qsTr("Convert...")
      onClicked: console.log("Convert button clicked")
    }
  }
}
