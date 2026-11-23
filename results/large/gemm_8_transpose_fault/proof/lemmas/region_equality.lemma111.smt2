; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_56 () (_ BitVec 32))
(declare-fun arg0_8 () (_ BitVec 32))
(declare-fun arg1_7 () (_ BitVec 32))
(assert
 (let ((?x63388 (bvmul arg0_8 arg1_56)))
(let ((?x71346 (bvmul (_ bv4294967295 32) ?x63388)))
(let ((?x9529 (bvmul arg0_8 arg1_7)))
(let ((?x57135 (bvadd ?x9529 ?x71346)))
(and (distinct ?x57135 (_ bv0 32)) true))))))
(check-sat)
