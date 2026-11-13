; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_7 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(assert
 (let ((?x371593 (bvmul arg0_7 arg1_7)))
(let ((?x21027 (bvmul (_ bv4294967295 32) ?x371593)))
(and (distinct ?x21027 (_ bv0 32)) true))))
(check-sat)
