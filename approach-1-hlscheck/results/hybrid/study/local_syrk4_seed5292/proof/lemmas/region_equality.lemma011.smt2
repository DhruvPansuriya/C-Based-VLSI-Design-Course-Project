; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(assert
 (let ((?x489856 (bvmul arg0_1 arg0_7)))
(let ((?x453805 (bvmul (_ bv4294967295 32) ?x489856)))
(let ((?x488183 (bvmul arg0_1 arg0_13)))
(let ((?x469735 (bvadd ?x488183 ?x453805)))
(and (distinct ?x469735 (_ bv0 32)) true))))))
(check-sat)
