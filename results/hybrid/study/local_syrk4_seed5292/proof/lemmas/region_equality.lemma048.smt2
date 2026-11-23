; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(assert
 (let ((?x502621 (bvmul arg0_13 arg0_7)))
(let ((?x512807 (bvmul (_ bv4294967295 32) ?x502621)))
(let ((?x428839 (bvmul arg0_13 arg0_13)))
(let ((?x475230 (bvadd ?x428839 ?x512807)))
(and (distinct ?x475230 (_ bv0 32)) true))))))
(check-sat)
