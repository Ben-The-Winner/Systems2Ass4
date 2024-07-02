#include "complex.h"
#include "tree.h"
#include <QApplication>
#include <QMainWindow>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QVBoxLayout>
#include <QWidget>
using namespace std;

void addTreeItem(QTreeWidgetItem* parentItem, std::shared_ptr<Node<Complex>> node) {
    if (!node) return;
    QString text = QString::number(node->data.real, 'f', 2) + " + " + QString::number(node->data.imag, 'f', 2) + "i";
    auto* item = new QTreeWidgetItem(parentItem, QStringList(text));
    parentItem->addChild(item);
    for (const auto& child : node->children) {
        addTreeItem(item, child);
    }
}


int main(int argc, char *argv[]) {
    Tree<Complex> tree(Complex(10, 10), 3);

    auto child1 = tree.add_sub_node(tree.root, Complex(15, 5));
    auto child2 = tree.add_sub_node(tree.root, Complex(30, 20));
    auto child3 = tree.add_sub_node(tree.root, Complex(8, 20.5));

    if (child1) {
        tree.add_sub_node(child1, Complex(25, 10));
        tree.add_sub_node(child1, Complex(35, 15));
    }

    if (child2) {
        tree.add_sub_node(child2, Complex(45, 25));
        tree.add_sub_node(child2, Complex(50, 30));
    }

    if (child3) {
        tree.add_sub_node(child3, Complex(12.1589, 25));
        tree.add_sub_node(child3, Complex(40.856, 30));
        tree.add_sub_node(child3, Complex(69, 4.20));
    }

    // Print the tree using various traversal methods
    cout << "Preorder traversal: ";
    cout << tree << endl;

    cout << "Postorder traversal: ";
    cout >> tree;
    cout << endl;

    cout << "Inorder traversal: ";
    cout | tree;
    cout << endl;

    cout << "BFS traversal: ";
    cout % tree;
    cout << endl;

    cout << "DFS traversal: ";
    cout & tree;
    cout << endl;

    QApplication app(argc, argv);

    QMainWindow window;
    QWidget *centralWidget = new QWidget();
    QVBoxLayout *layout = new QVBoxLayout();

    QTreeWidget *treeWidget = new QTreeWidget();
    treeWidget->setColumnCount(1);
    treeWidget->setHeaderLabel("Tree");

    auto* rootItem = new QTreeWidgetItem(treeWidget, QStringList(QString::fromStdString(to_string(tree.root->data.real) + " + " + to_string(tree.root->data.imag) + "i")));
    treeWidget->addTopLevelItem(rootItem);
    for (const auto& child : tree.root->children) {
        addTreeItem(rootItem, child);
    }

    layout->addWidget(treeWidget);
    centralWidget->setLayout(layout);
    window.setCentralWidget(centralWidget);
    window.setWindowTitle("Tree Viewer");
    window.show();

    return app.exec();
}
