/**
Copyright 2019 Siddhi-LLVM Team
Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include <iostream>
#include <fstream>
#include <thread>
#include "antlr4-runtime.h"
#include "SiddhiqlLexer.h"
#include "SiddhiqlParser.h"
#include "SiddhiqlBaseListener.h"
#include "stream-processor-generator/src/antlr/TranslatorVisitor.h"
#include "stream-processor-generator/src/antlr/TranslatorVisitor.h"
#include "queue"
#include "BufferGenerator.h"
#include "DetailContainerCreator.h"

using namespace antlrcpp;
using namespace antlr4;
using namespace std;

int main ( int argc, const char *args[]){
    ifstream stream1;
    stream1.open("/home/tharsanan/Tharsanan/FYP/siddhi-llvm/sample.exec");
    ANTLRInputStream input1(stream1);
    SiddhiqlLexer lexer1(&input1);
    CommonTokenStream tokens1(&lexer1);
    SiddhiqlParser parser1(&tokens1);
    TranslatorVisitor translatorVisitor;
    SiddhiqlParser :: Siddhi_appContext * visitTree = parser1.siddhi_app();
    translatorVisitor.visitSiddhi_app(visitTree);
    AttributeTypeMapper attributeTypeMapper;
    BufferGenerator bufferGenerator;
    string argString = "";
    int count  = 0;
    for(auto const& x : AttributeTypeMapper::getInputAttributeMap()){
        if(count == 0){
            argString += x.first + " " + x.second;
        }
        else{
            argString += + "," + x.first + " " + x.second;
        }
        count++;
    }
    bufferGenerator.readArgs(argString);
    for (int i = 0; i < TranslatorVisitor::getInputOutputMapperList().size(); ++i) {
        bufferGenerator.iomappers.push_back(TranslatorVisitor::getInputOutputMapperFromList(i));
    }
    bufferGenerator.createViaFileCreator();
    DetailContainerCreator detailContainerCreator;
    detailContainerCreator.create();




    return 0;
}