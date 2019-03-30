#include <ostream>
#include <string>
#include <memory>
#include <iostream>
#include <sstream>
#include <regex>
#include <vector>


struct SmartTree {
    int value;
    int childrens = 0;
    bool is_root = false;
    std::unique_ptr<SmartTree> LeftChild;
    std::unique_ptr<SmartTree> RightChild;
};




std::unique_ptr <SmartTree> CreateLeaf(int value);
std::unique_ptr <SmartTree> InsertLeftChild(std::unique_ptr<SmartTree>  subtree, std::unique_ptr<SmartTree> left_subtree);
std::unique_ptr <SmartTree> InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree);

void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr , std::ostream * out);

std::string DumpTree(const std::unique_ptr<SmartTree> &tree);
std::unique_ptr <SmartTree> RestoreTree(std::string &tree);
void InOrderTreeWalk(const std::unique_ptr<SmartTree> &unique_ptr);

int main (){
    std::unique_ptr < SmartTree> Root = CreateLeaf(150);
    Root -> is_root = true;
    std::string dumped;
    bool running = true;
    while (running) {
        std::cout << "Option 1 - insert left / 2 - insert right / 3 - print / 4 - dump / 5 - refresh / 6 - exit " << std::endl;
        int option;
        std::cin >> option;
        switch (option) {
            case (1): {

                std::cout << "Child value:" << std::endl;
                int child;
                std::cin >> child;
                std::unique_ptr<SmartTree> NewLeaf = CreateLeaf(child);
                std::unique_ptr<SmartTree> NewTree = InsertLeftChild(std::move(Root), std::move(NewLeaf));
                Root = std::move(NewTree);
                break;
            }
            case (2):{
                std::cout << "Child value:" << std::endl;
                int child;
                std::cin >> child;
                std::unique_ptr<SmartTree> NewLeaf = CreateLeaf(child);
                std::unique_ptr<SmartTree> NewTree = InsertRightChild(std::move(Root), std::move(NewLeaf));
                Root = std::move(NewTree);
                break;
            }
            case (3): {
                PrintTreeInOrder(Root , &std::cout);
                std::cout << "In order tree walk";

                break;
            }
            case (4):{
                dumped = DumpTree(Root);
                std::cout << dumped;
                //czy nie jest ten wiersz zbędny ?
                Root = nullptr;
                break;
            }
            case (5):{
                Root = std::move(RestoreTree(dumped));
                break;
            }
            case (6): {
                running = false;
                break;
            }
            default: {
                std::cout << "No such option" << std::endl;
                break;
            }
        }

    }
    return 0;
}

std::unique_ptr <SmartTree> CreateLeaf(int value){
    std::unique_ptr<SmartTree> Leaf = std::make_unique<SmartTree>();
    Leaf -> value = value;
    Leaf -> childrens = 0;
    Leaf -> LeftChild = nullptr;
    Leaf -> RightChild = nullptr;
    return Leaf;
};

std::unique_ptr <SmartTree> InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree){
    // left_subtree - node to insert
    tree -> childrens += 1;
    if (tree -> is_root and  tree -> LeftChild == nullptr) tree -> LeftChild = std::move(left_subtree);
    else if (tree -> is_root) tree -> LeftChild = InsertLeftChild(std::move(tree -> LeftChild) , move(left_subtree));
    else if (tree -> LeftChild == nullptr)tree -> LeftChild = std::move(left_subtree);
    else if (tree -> RightChild == nullptr) tree -> RightChild = std::move(left_subtree);
    else if (tree -> LeftChild -> childrens <= tree -> RightChild -> childrens) tree->LeftChild = InsertLeftChild(std::move(tree -> LeftChild) , std::move(left_subtree));
    else if (tree -> LeftChild -> childrens > tree -> RightChild -> childrens)  tree->RightChild = InsertLeftChild(std::move(tree -> RightChild) , std::move(left_subtree));
    return move(tree);
};


std::unique_ptr <SmartTree> InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree){
    tree -> childrens += 1;
    if (tree -> is_root and  tree -> RightChild == nullptr) tree -> RightChild = std::move(right_subtree);
    else if (tree -> is_root) tree -> RightChild = InsertRightChild(std::move(tree -> RightChild) , move(right_subtree));
    else if (tree -> LeftChild == nullptr)tree -> LeftChild = std::move(right_subtree);
    else if (tree -> RightChild == nullptr) tree -> RightChild = std::move(right_subtree);
    else if (tree -> LeftChild -> childrens <= tree -> RightChild -> childrens) tree->LeftChild = InsertRightChild(std::move(tree -> LeftChild) , std::move(right_subtree));
    else if (tree -> LeftChild -> childrens > tree -> RightChild -> childrens)  tree->RightChild = InsertRightChild(std::move(tree -> RightChild) , std::move(right_subtree));
    return move(tree);
};



void InOrderTreeWalk(const std::unique_ptr<SmartTree> &unique_ptr){
    if(unique_ptr != nullptr){
        InOrderTreeWalk(unique_ptr -> LeftChild);
        std::cout << unique_ptr ->value << std::endl;
        InOrderTreeWalk(unique_ptr -> RightChild);
    }
}





void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr , std::ostream * out){
    if (unique_ptr == nullptr){
        return;
    }
    if (unique_ptr -> is_root and out != &std::cout and unique_ptr -> RightChild != nullptr) (*out) << unique_ptr -> RightChild -> childrens + 1 << " ";
    else if (unique_ptr -> is_root and unique_ptr -> RightChild == nullptr) (*out) << 0 << " ";
    PrintTreeInOrder(unique_ptr-> LeftChild , out);
    (*out) <<  unique_ptr -> value <<  "  " ;
    PrintTreeInOrder(unique_ptr -> RightChild , out);

};

std::string DumpTree(const std::unique_ptr<SmartTree> &tree){
    std::ostringstream dumpedTree;
    PrintTreeInOrder(tree , &dumpedTree);
    std::string dumped = dumpedTree.str();
    return dumped;

};

std::unique_ptr <SmartTree> RestoreTree(std::string &tree)
{
    std::vector <int> edges;
    std::regex node (R"(([0-9]+))");
    std::regex_token_iterator<std::string::iterator> rend;
    std::regex_token_iterator<std::string::iterator> a ( tree.begin(), tree.end(), node );
    while (a!=rend) edges.push_back(stoi(*a++));
    std::cout << std::endl;
    int parent = edges.size() - edges[0] - 1 ;
    std::unique_ptr < SmartTree> Root = CreateLeaf(edges[parent]);
    Root -> is_root = true;
    for(int i = parent - 1 ; i > 0 ; --i){
        std::unique_ptr<SmartTree> NewLeaf = CreateLeaf(edges[i]);
        std::unique_ptr<SmartTree> NewTree = InsertLeftChild(std::move(Root), std::move(NewLeaf));
        Root = std::move(NewTree);
    }
    for(int i = edges.size() - 1; i > parent ; --i){
        std::unique_ptr<SmartTree> NewLeaf = CreateLeaf(edges[i]);
        std::unique_ptr<SmartTree> NewTree = InsertRightChild(std::move(Root), std::move(NewLeaf));
        Root = std::move(NewTree);
    }
    return Root;
}

