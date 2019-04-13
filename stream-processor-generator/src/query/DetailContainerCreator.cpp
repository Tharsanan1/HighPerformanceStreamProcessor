//
// Created by tharsanan on 4/13/19.
//

#include "DetailContainerCreator.h"

DetailContainerCreator::DetailContainerCreator(){

}

void DetailContainerCreator::create(){
    ClassCreator detailContainer;
    detailContainer.className = "DetailContainer";

    Method methodGetNumberOfOutputAttributes;
    methodGetNumberOfOutputAttributes.isStatic = true;
    methodGetNumberOfOutputAttributes.identifier = "getNumberOfOutputAttributes";
    methodGetNumberOfOutputAttributes.returnType = "int";
    methodGetNumberOfOutputAttributes.addLine("return numberOfOutputAttributes");
    detailContainer.publicMembers.publicMethods.push_back(methodGetNumberOfOutputAttributes);

    Variable numberOfOutputAttributes;
    numberOfOutputAttributes.isStatic = true;
    numberOfOutputAttributes.initValue = to_string(AttributeTypeMapper::getOutputAttributeMap().size());
    numberOfOutputAttributes.dataType = "int";
    numberOfOutputAttributes.identifier = "numberOfOutputAttributes";
    detailContainer.publicMembers.publicVariables.push_back(numberOfOutputAttributes);

    detailContainer.createHeaderSource();
    detailContainer.createCppSource();
}