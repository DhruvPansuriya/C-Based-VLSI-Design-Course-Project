; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_7 () (_ BitVec 32))
(declare-fun arg0_15 () (_ BitVec 32))
(declare-fun arg1_56 () (_ BitVec 32))
(assert
 (let ((?x75225 (bvmul arg0_15 arg1_7)))
(let ((?x55210 (bvmul (_ bv4294967295 32) ?x75225)))
(let ((?x75501 (bvmul arg0_15 arg1_56)))
(let ((?x58301 (bvadd ?x75501 ?x55210)))
(and (distinct ?x58301 (_ bv0 32)) true))))))
(check-sat)
