; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_3 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg0_3 () (_ BitVec 32))
(assert
 (let ((?x470155 (bvmul arg0_2 arg1_3)))
(let ((?x573528 (bvmul (_ bv4294967295 32) ?x470155)))
(let ((?x338720 (bvmul arg0_3 arg1_3)))
(let ((?x307913 (bvadd ?x338720 ?x573528)))
(and (distinct ?x307913 (_ bv0 32)) true))))))
(check-sat)
