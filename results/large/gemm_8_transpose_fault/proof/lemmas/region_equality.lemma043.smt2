; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_48 () (_ BitVec 32))
(declare-fun arg0_0 () (_ BitVec 32))
(declare-fun arg1_6 () (_ BitVec 32))
(assert
 (let ((?x73089 (bvmul arg0_0 arg1_48)))
(let ((?x60475 (bvmul (_ bv4294967295 32) ?x73089)))
(let ((?x29734 (bvmul arg0_0 arg1_6)))
(let ((?x67855 (bvadd ?x29734 ?x60475)))
(and (distinct ?x67855 (_ bv0 32)) true))))))
(check-sat)
