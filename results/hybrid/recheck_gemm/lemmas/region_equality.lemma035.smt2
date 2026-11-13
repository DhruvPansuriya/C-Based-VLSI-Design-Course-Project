; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_12 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg1_3 () (_ BitVec 32))
(assert
 (let ((?x168 (bvmul arg0_8 arg1_12)))
(let ((?x8485 (bvmul (_ bv4294967295 32) ?x168)))
(let ((?x107 (bvmul arg0_8 arg1_3)))
(let ((?x9818 (bvadd ?x107 ?x8485)))
(and (distinct ?x9818 (_ bv0 32)) true))))))
(check-sat)
