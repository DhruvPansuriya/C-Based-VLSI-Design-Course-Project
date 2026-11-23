; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_3 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg2_4 () (_ BitVec 32))
(assert
 (let ((?x340473 (bvmul arg0_7 arg2_3)))
(let ((?x475394 (bvmul (_ bv4294967295 32) ?x340473)))
(let ((?x294187 (bvmul arg0_7 arg2_4)))
(let ((?x470155 (bvadd ?x294187 ?x475394)))
(and (distinct ?x470155 (_ bv0 32)) true))))))
(check-sat)
