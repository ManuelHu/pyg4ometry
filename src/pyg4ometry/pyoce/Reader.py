from .oce import *
from .funcs import *

class Reader :
    def __init__(self, fileName):
        self.xcaf = XCAF()
        self.readFile(fileName)

    def readFile(self,fileName):
        self.fileName = fileName
        self.xcaf.loadStepFile(self.fileName)
        self.shapeTool = self.xcaf.shapeTool()

    def freeShapes(self):
        ls = TDF_LabelSequence()
        self.shapeTool.GetFreeShapes(ls)
        return ls

    def traverse(self,label = None):

        name = find_TDataStd_Name_From_Label(label)
        loc  = find_XCAFDoc_Location_From_Label(label)

        print(name, shapeTypeString(self.shapeTool,label),loc)

        for i in range(1,label.NbChildren()+1,1) :
            b, child = label.FindChild(i,False)
            self.traverse(child)

        rlabel = TDF_Label()
        self.shapeTool.GetReferredShape(label, rlabel)
        if not rlabel.IsNull() :
            self.traverse(rlabel)

