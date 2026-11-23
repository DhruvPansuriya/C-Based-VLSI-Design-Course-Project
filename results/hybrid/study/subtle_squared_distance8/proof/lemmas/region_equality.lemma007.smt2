; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_6 () (_ BitVec 32))
(declare-fun arg0_6 () (_ BitVec 32))
(assert
 (let ((?x470155 (bvmul arg0_6 arg1_6)))
(let ((?x348914 (bvmul (_ bv4294967295 32) ?x470155)))
(and (distinct ?x348914 (_ bv0 32)) true))))
(check-sat)
