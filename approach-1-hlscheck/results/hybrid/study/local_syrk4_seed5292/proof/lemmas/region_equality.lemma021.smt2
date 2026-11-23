; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg0_5 () (_ BitVec 32))
(declare-fun arg0_9 () (_ BitVec 32))
(assert
 (let ((?x90442 (bvmul arg0_5 arg0_6)))
(let ((?x106246 (bvmul (_ bv4294967295 32) ?x90442)))
(let ((?x470122 (bvmul arg0_5 arg0_9)))
(let ((?x427307 (bvadd ?x470122 ?x106246)))
(and (distinct ?x427307 (_ bv0 32)) true))))))
(check-sat)
