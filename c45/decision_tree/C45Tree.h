#ifndef C45_C45TREE_H
#define C45_C45TREE_H

#include "../data/Dataset.h"

#include <string>
#include <map>

class C45Tree {
private:
    std::map<std::string, C45Tree*> _children;
    std::string _className;
public:
    explicit C45Tree(const Dataset& originDataset);

    std::vector<std::string> getChildrenNames() const;
    std::string getClassName() const;

    C45Tree * getChild(const std::string& name);

    ~C45Tree();
};


#endif //C45_C45TREE_H
