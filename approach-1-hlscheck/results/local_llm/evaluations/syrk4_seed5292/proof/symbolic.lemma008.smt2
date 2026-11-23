; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_6 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg0_9 () (_ BitVec 32))
(assert
 (let ((?x782 (bvmul arg0_1 arg0_6)))
(let ((?x23847 (bvmul (_ bv4294967295 32) ?x782)))
(let ((?x89 (bvmul arg0_1 arg0_9)))
(let ((?x1291 (bvadd ?x89 ?x23847)))
(and (distinct ?x1291 (_ bv0 32)) true))))))
(check-sat)
