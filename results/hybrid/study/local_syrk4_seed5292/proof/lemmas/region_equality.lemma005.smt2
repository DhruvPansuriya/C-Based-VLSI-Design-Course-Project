; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_3 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(declare-fun arg0_7 () (_ BitVec 32))
(assert
 (let ((?x450611 (bvmul arg0_13 arg0_3)))
(let ((?x456851 (bvmul (_ bv4294967295 32) ?x450611)))
(let ((?x490781 (bvmul arg0_3 arg0_7)))
(let ((?x5993 (bvadd ?x490781 ?x456851)))
(and (distinct ?x5993 (_ bv0 32)) true))))))
(check-sat)
